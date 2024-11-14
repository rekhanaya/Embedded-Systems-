#include "DHT.h"

#define DHTPIN D4      // Pin yang digunakan untuk sensor DHT
#define DHTTYPE DHT22  // Tipe sensor DHT yang digunakan (DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);  // Memulai komunikasi serial
  dht.begin();         // Memulai sensor DHT
}

void loop() {
  delay(2000);  // Delay 2 detik antar pembacaan

  // Membaca kelembaban dan suhu dari sensor DHT
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Memeriksa apakah pembacaan dari sensor gagal
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Menampilkan suhu ke serial monitor
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Menampilkan kelembaban ke serial monitor
  Serial.print("Kelembaban: ");
  Serial.print(humidity);
  Serial.println("%");
}
