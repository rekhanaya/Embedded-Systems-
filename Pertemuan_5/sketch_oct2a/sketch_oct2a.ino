#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C mylcd(0x27,16,2);
int trigpin = 8;
int echopin = 9;
float durasi;
int jarak;

void setup() {
  // put your setup code here, to run once:
  mylcd.init();
  mylcd.backlight();
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);

  durasi=pulseIn(echopin, HIGH);
  Serial.print("Durasi: ");
  Serial.println(durasi);

  jarak=durasi*0.017;
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println("Cm");
  delay(100);

  mylcd.clear();
  mylcd.println("Durasi: ");
  mylcd.setCursor(8,0);
  mylcd.println(durasi);
  mylcd.setCursor(0,1);
  mylcd.println("Jarak: ");
  mylcd.setCursor(7,1);
  mylcd.println(jarak);
  mylcd.setCursor(12,1);
  mylcd.println("Cm");
  delay(500);
}
