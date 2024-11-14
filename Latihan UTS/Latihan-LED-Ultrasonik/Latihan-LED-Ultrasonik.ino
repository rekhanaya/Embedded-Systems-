int trigPin = 7;     // Pin untuk Trigger
int echoPin = 6;     // Pin untuk Echo
long durasi, jarak;  // Variabel untuk menyimpan durasi dan jarak
int led = 13;        // Pin LED

void setup() {
  Serial.begin(9600);        // Memulai komunikasi serial
  pinMode(led, OUTPUT);      // Menetapkan pin LED sebagai output
  pinMode(trigPin, OUTPUT);  // Menetapkan pin trig sebagai output
  pinMode(echoPin, INPUT);   // Menetapkan pin echo sebagai input
}

void loop() {
  // Mengirimkan pulsa trigger
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mengukur durasi sinyal pantulan (echo)
  durasi = pulseIn(echoPin, HIGH);
  
  // Menghitung jarak berdasarkan durasi
  jarak = (durasi * 0.034) / 2;
  
  // Menampilkan jarak pada serial monitor
  Serial.print(jarak);
  Serial.println(" cm");

  // Menyalakan LED jika jarak kurang dari 5 cm
  if (jarak < 5) {
    digitalWrite(led, HIGH);  // LED menyala
  } else {
    digitalWrite(led, LOW);   // LED mati
  }

  delay(100);  // Delay sebelum pengukuran berikutnya
}
