// VCC: 5V (koneksikan ke 5V di Arduino)
// Trig: Pin digital (misal: pin 9 di Arduino)
// Echo: Pin digital (misal: pin 10 di Arduino)
// GND: Ground

// Definisikan pin yang terhubung ke trig dan echo pada sensor ultrasonik
const int trigPin = 9;
const int echoPin = 10;

// Variabel untuk menyimpan durasi dan jarak
long durasi;
int jarak;

void setup() {
  // Inisialisasi komunikasi serial pada baud rate 9600
  Serial.begin(9600);

  // Set trigPin sebagai output dan echoPin sebagai input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Mulai dengan memastikan trigPin low
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Kirim sinyal ultrasonik selama 10 mikrodetik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca durasi dari echoPin (waktu pantulan sinyal ultrasonik)
  durasi = pulseIn(echoPin, HIGH);

  // Hitung jarak (durasi dikali 0.0343 lalu dibagi 2)
  jarak = durasi * 0.034 / 2;

  // Tampilkan jarak pada Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  // Delay 500 ms sebelum pengukuran berikutnya
  delay(500);
}
