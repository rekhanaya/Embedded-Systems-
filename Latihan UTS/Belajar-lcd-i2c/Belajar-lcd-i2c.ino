// VCC: 5V
// GND: Ground
// SDA: Pin A4 (untuk Arduino Uno)
// SCL: Pin A5 (untuk Arduino Uno)

// belajar lcd i2c

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  // pesan pertama
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Halo");

  lcd.setCursor(6, 1);
  lcd.print("Manusia!");
  delay(5000);
// ===========================

  // pesan kedua  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Halo");

  lcd.setCursor(6, 1);
  lcd.print("juga");
  delay(5000);
}
