#include <Servo.h>

Servo servo;

int trig1 = 9;
int echo1 = 8;
int irSensor = 7;  // Menggunakan pin 7 untuk IR sensor
int buzzer = 12;

long durasi, jarak;
unsigned long stopTime = 0; // Waktu ketika kendaraan berhenti di tengah
bool vehicleStopped = false; // Status untuk melacak apakah kendaraan berhenti

void setup() {
  servo.attach(6);
  servo.write(90);  // Mulai dengan palang pintu tertutup pada sudut 90 derajat
  Serial.begin(9600);

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(irSensor, INPUT);  // Set IR sensor sebagai input
  pinMode(buzzer, OUTPUT);   // Set pin buzzer sebagai output
}

void loop() {
  // Sensor Ultrasonik (Exit sensor)
  digitalWrite(trig1, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  durasi = pulseIn(echo1, HIGH);
  jarak = (durasi * 0.034) / 2;

  // Baca status IR sensor (Entry sensor)
  int irStatus = digitalRead(irSensor);

  // Tampilkan jarak dari sensor ultrasonik untuk debugging
  Serial.print("Jarak Sensor Ultrasonik: ");
  Serial.println(jarak);
  Serial.print("Status IR Sensor: ");
  Serial.println(irStatus);

  // Logika kontrol palang pintu dan alarm
  if (jarak < 20 && irStatus == HIGH) { 
    // Kendaraan meninggalkan kompleks
    servo.write(0);  // Buka palang pintu ke 0 derajat
    Serial.println("Kendaraan Melintas Keluar");
    noTone(buzzer);
    stopTime = 0;  // Reset stop time karena kendaraan sudah pergi
    vehicleStopped = false;
  } 
  else if (irStatus == LOW && jarak > 20) { 
    // Kendaraan memasuki kompleks
    servo.write(90);  // Tutup palang pintu ke 90 derajat
    Serial.println("Kendaraan Melintas Masuk");
    tone(buzzer, 1000);  // Bunyi bip singkat
    delay(500);
    noTone(buzzer);
    stopTime = 0;  // Reset stop time karena kendaraan baru masuk
    vehicleStopped = false;
  } 
  else if (irStatus == LOW && jarak < 20) {
    // Kendaraan berada di tengah palang pintu
    Serial.println("Kendaraan berada di tengah palang pintu");
    servo.write(90);  // Tetap tutup palang pintu
    if (!vehicleStopped) {
      stopTime = millis();  // Mulai penghitungan waktu ketika kendaraan berhenti
      vehicleStopped = true;
    }
  }

  // Cek jika kendaraan berhenti lebih dari 5 detik di tengah
  if (vehicleStopped && (millis() - stopTime > 5000)) {
    tone(buzzer, 1000);  // Bunyi bip terus-menerus jika kendaraan berhenti lebih dari 5 detik
  }

  delay(500);  // Delay kecil untuk pembacaan sensor yang lebih stabil
}
