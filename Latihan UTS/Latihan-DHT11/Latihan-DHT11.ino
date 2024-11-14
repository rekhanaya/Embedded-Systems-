///////////////////////////// LATIHAN DHT11 /////////////////////////////////////////////////
#include <DHT.h>

#define DHTPIN 2     // Pin data sensor DHT terhubung ke pin digital 2
#define DHTTYPE DHT11   // Definisikan tipe sensor (DHT11 atau DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);        // Memulai komunikasi serial
  dht.begin();               // Inisialisasi sensor DHT
}

void loop() {
  // Tunggu beberapa detik antara pengukuran
  delay(2000);

  // Membaca kelembaban
  float kelembaban = dht.readHumidity();
  // Membaca suhu dalam Celsius
  float suhuC = dht.readTemperature();
  // Membaca suhu dalam Fahrenheit
  float suhuF = dht.readTemperature(true);

  // Cek apakah pembacaan gagal
  if (isnan(kelembaban) || isnan(suhuC) || isnan(suhuF)) {
    Serial.println("Gagal membaca dari sensor DHT!");
    return;
  }

  // Menampilkan data ke Serial Monitor
  Serial.print("Kelembaban: ");
  Serial.print(kelembaban);
  Serial.print(" %\t");
  Serial.print("Suhu: ");
  Serial.print(suhuC);
  Serial.print(" *C ");
  Serial.print(suhuF);
  Serial.println(" *F");
}
