// VCC: 5V
// GND: Ground
// Signal: Pin digital (misal: pin 6 di Arduino)

// belajar servo motor

#include <Servo.h>

// deklarasi pin servo
const  int pinServo = 8;
// deklarasi objek servo
Servo myServo;

void setup() {
  // inisialisasi pin servo motor sebagai output
  pinMode(pinServo, OUTPUT);
  // inisialisasi objek servo
  myServo.attach(pinServo);
  // myServo.write(0);
}

void loop() {
  // menggerakkan servo ke posisi 0 derajat
  myServo.write(0);
  delay(1000);

  // menggerakan servo ke posisi 90 derajat
  myServo.write(90);
  delay(1000);

  // menggerakan servo ke posisi 90 derajat
  myServo.write(180);
  delay(1000);
}
