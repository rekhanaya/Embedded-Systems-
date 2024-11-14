#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); 

void setup() {
 lcd.init();
 lcd.backlight();
 lcd.clear(); 
}

void loop() {
 lcd.setCursor(2, 0); 
 lcd.print("Informatika"); 
 lcd.setCursor(6, 1); 
 lcd.print("UPJ");
}