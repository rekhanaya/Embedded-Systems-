#include <Servo.h>

Servo servo;

int ir1 = 9;  // IR sensor 1 (keluar)
int ir2 = 11; // IR sensor 2 (masuk)
int buzzer = 12;

bool vehicleStopped = false;  // Status untuk melacak apakah kendaraan berhenti
int stopDuration = 0;         // Menyimpan lama waktu kendaraan berhenti
int stopThreshold = 5000;     // Batas waktu berhenti (5 detik)

void setup() {
  servo.attach(6);
  servo.write(90);  // Mulai dengan palang tertutup pada 90 derajat
  Serial.begin(9600);

  pinMode(ir1, INPUT);  // Pin IR sensor untuk keluar
  pinMode(ir2, INPUT);  // Pin IR sensor untuk masuk
  pinMode(buzzer, OUTPUT); // Set pin buzzer sebagai output
}

void loop() {
  // Membaca nilai dari sensor IR
  int sensorKeluar = digitalRead(ir1);  // 0 jika ada objek, 1 jika tidak ada objek
  int sensorMasuk = digitalRead(ir2);   // 0 jika ada objek, 1 jika tidak ada objek

  // Print nilai sensor untuk debugging
  Serial.print("Sensor IR Keluar: ");
  Serial.println(sensorKeluar);
  Serial.print("Sensor IR Masuk: ");
  Serial.println(sensorMasuk);

  // Logika kontrol palang dan alarm
  if (sensorKeluar == LOW && sensorMasuk == HIGH) { 
    // Kendaraan keluar
    servo.write(0);  // Buka palang ke 0 derajat
    Serial.println("Kendaraan Melintas Keluar");
    noTone(buzzer);
    vehicleStopped = false;  // Reset status kendaraan berhenti
    stopDuration = 0;  // Reset durasi berhenti
  } 
  else if (sensorMasuk == LOW && sensorKeluar == HIGH) { 
    // Kendaraan masuk
    servo.write(90);  // Tutup palang ke 90 derajat
    Serial.println("Kendaraan Melintas Masuk");
    tone(buzzer, 1000);  // Bip pendek
    delay(500);
    noTone(buzzer);
    vehicleStopped = false;  // Reset status kendaraan berhenti
    stopDuration = 0;  // Reset durasi berhenti
  } 
  else if (sensorMasuk == LOW && sensorKeluar == LOW) {
    // Kendaraan di tengah palang
    Serial.println("Mobil berada pada tengah palang pintu");
    servo.write(90);  // Tetap tutup palang

    // Jika kendaraan baru berhenti, mulai menghitung durasi berhenti
    if (!vehicleStopped) {
      vehicleStopped = true;
      stopDuration = 0;  // Reset durasi berhenti
    }
    
    // Jika kendaraan sudah berhenti, mulai menghitung waktu
    stopDuration += 500;  // Tambah durasi berhenti sebesar delay
    delay(500);  // Menunggu 500 milidetik

    // Jika kendaraan berhenti lebih dari 5 detik, bunyikan alarm
    if (stopDuration >= stopThreshold) {
      tone(buzzer, 1000);  // Bip terus menerus jika kendaraan berhenti lebih dari 5 detik
    }
  } else {
    // Jika tidak ada kendaraan di tengah, reset status berhenti
    vehicleStopped = false;
    stopDuration = 0;
  }

  delay(500);  // Delay untuk pembacaan sensor yang lebih halus
}
