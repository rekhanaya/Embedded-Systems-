///////////////////////////// KASUS 2 Belajar Servo dan LED /////////////////////////////////////////////////
#include <Servo.h>

Servo servo1;
int led = 13;

void setup()
{

  servo1.attach(9);
  servo1.write(90);
  delay(3000);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

}

void loop()
{
  servo1.write(0);
  delay(1000);
  servo1.write(90);
  if(servo1.read() == 90){
    digitalWrite(led, HIGH);
  }
  delay(1000);
  digitalWrite(led, LOW);
  servo1.write(180);
  if(servo1.read() == 180){
    digitalWrite(led, HIGH);
  }
  delay(1000);
  digitalWrite(led, LOW);
  servo1.write(270);
  if(servo1.read() == 270){
      digitalWrite(led, HIGH);
    }
  delay(1000);
  digitalWrite(led, LOW);
}

