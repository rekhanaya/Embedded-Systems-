///////////////////////////// KASUS 3 Ukur Jarak dengan Servo  /////////////////////////////////////////////////

#include <Servo.h>

const int trigPin = 12;   // Pin 12 untuk trigger ultrasonik
const int echoPin = 11;   // Pin 11 untuk echo ultrasonik
int ledPin = 13;          // Pin 13 untuk LED (indikator)
long durasi;              // Variabel untuk menyimpan durasi pulse dari echo
float jarak;              // Variabel untuk menyimpan hasil jarak dalam cm
// int sensorPin = 7;
Servo servo1;


void setup() {
  pinMode(trigPin, OUTPUT);  // Atur trigPin sebagai output untuk memicu sinyal ultrasonik
  pinMode(echoPin, INPUT);   // Atur echoPin sebagai input untuk menerima sinyal pantulan (echo)
  pinMode(ledPin, OUTPUT);   // Atur ledPin sebagai output untuk LED indikator
  digitalWrite(ledPin, LOW); // Matikan LED awalnya
  Serial.begin(9600);        // Memulai komunikasi serial dengan baud rate 9600
  pinMode(sensorPin, INPUT);
  servo1.attach(9);
  servo1.write(180);
  delay(3000);

}

void loop() {
  // Mengirimkan sinyal trigger
  digitalWrite(trigPin, LOW);           // Pastikan trigger awalnya LOW
  delayMicroseconds(2);                 // Tunggu sebentar selama 2 mikrodetik
  digitalWrite(trigPin, HIGH);          // Kirimkan sinyal trigger HIGH selama 10 mikrodetik
  delayMicroseconds(10);                // Tunggu selama 10 mikrodetik
  digitalWrite(trigPin, LOW);           // Kembalikan trigger ke LOW

  // Mengukur durasi sinyal HIGH pada echoPin
  durasi = pulseIn(echoPin, HIGH);      // Mengukur durasi sinyal HIGH pada pin echo

  // Menghitung jarak dalam cm
  jarak = (durasi * 0.034) / 2;         // Menghitung jarak dari durasi echo
  
  // int sensorNilai = digitalRead(sensorPin);

  if(jarak <= 100){
    Serial.println("Objek terdeteksi");
    digitalWrite(ledPin, HIGH);
    servo1.write(90)
  }
  delay(1000);

  if(jarak >= 100){
    Serial.println("Objek tidak terdeteksi");
    digitalWrite(ledPin, LOW);
    servo1.write(180)
  }
  delay(1000);


  // // Menampilkan hasil pengukuran di Serial Monitor
  // Serial.print("Durasi Pulse: ");       // Menampilkan durasi pulse
  // Serial.print(durasi);                 // Menampilkan nilai durasi
  // Serial.print(" mikrodetik, Jarak: "); // Menampilkan teks 'Jarak'
  // Serial.print(jarak);                  // Menampilkan jarak yang dihitung
  // Serial.println(" cm");                // Menambahkan satuan cm

  // // Delay untuk jeda pembacaan berikutnya
  // delay(1000);                          // Tunggu selama 1 detik sebelum pembacaan berikutnya
}

