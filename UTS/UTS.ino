#include <LiquidCrystal_I2C.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin1 = 8; //sensor  keluar
int sensorPin2 = 9; //sensor keluar
int Orang = 0;
int orangMasukTerdeteksi = 0;
int orangKeluarTerdeteksi = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  delay(10);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorMasuk = digitalRead(sensorPin1);   //membaca IR sensor 1
  int sensorKeluar = digitalRead(sensorPin2); //membaca IR sensor 2
  
  if (sensorMasuk == LOW && orangMasukTerdeteksi == 0 )
  { 
    Orang++; 
    orangMasukTerdeteksi = 1;
    lcd.setCursor(0, 0);
    lcd.print("Orang Masuk ");
    lcd.setCursor(0, 1);
    lcd.print(Orang);
  } 
  if (sensorMasuk == HIGH)
  {
    orangMasukTerdeteksi = 0;
  }
  if (sensorKeluar == LOW && orangKeluarTerdeteksi == 0)
  {
    if (Orang > 0); {
      Orang--; 
    }
    orangKeluarTerdeteksi = 1;
    lcd.setCursor(0, 0);
    lcd.print("Orang Keluar= ");
    lcd.setCursor(0, 1);
    lcd.print(Orang);
  }

  if (sensorKeluar == HIGH)
  delay(100);
}
