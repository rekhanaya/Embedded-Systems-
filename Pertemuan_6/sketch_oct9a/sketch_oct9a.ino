#include <Servo.h>
#include <DHT.h>
#include <DHT_U.h>
#include <DHT.h>                          

// Definisikan pin untuk DHT11
#define DHTPIN 8                         
#define DHTTYPE DHT11                    
DHT dht(DHTPIN, DHTTYPE);                
Servo servoku;
int tunda=10000;

void setup() {
  servoku.attach(9);
  servoku.write(90);
  Serial.begin(9600);                    
  dht.begin();                           
  delay(5000);
}

void loop() {
  servoku.write(0);
  delay(tunda);
  servoku.write(90);
  delay(tunda);
  servoku.write(180);
  delay(tunda);
  servoku.write(90);
  delay(tunda);

  float h = dht.readHumidity();         
  float t = dht.readTemperature();      

  if (isnan(h) || isnan(t)) {         
    Serial.println("Gagal membaca dari DHT sensor!"); 
    return;                             
  }

  // Tampilkan hasil di Serial Monitor
  Serial.print("Kelembapan: ");         
  Serial.print(h);                      
  Serial.print("%  Suhu: ");            
  Serial.print(t);                      
  Serial.println("°C");                 
  delay(2000);                          
}
