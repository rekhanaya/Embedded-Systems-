///////////////// Kasus 4 SERVO //////////////////

#include <Servo.h>

Servo servo1;

void setup() {
  servo1.attach(9);    // Menghubungkan pin sinyal servo ke pin digital 9 pada Arduino
  servo1.write(90);     // Mengatur posisi awal servo pada 90 derajat
  delay(3000);          // Menunggu selama 3 detik
}

void loop() {
  servo1.write(0);      // Menggerakkan servo ke posisi 0 derajat
  delay(1000);          // Menunggu selama 1 detik
  servo1.write(90);     // Menggerakkan servo kembali ke posisi 90 derajat
  delay(1000);          // Menunggu selama 1 detik
  servo1.write(180);    // Menggerakkan servo ke posisi 180 derajat
  delay(1000);          // Menunggu selama 1 detik
  servo1.write(90);     // Menggerakkan servo kembali ke posisi 90 derajat
  delay(1000);          // Menunggu selama 1 detik
}


//Kabel VCC (5v) biasanya berwarna merah, sedangkan kabel GND biasanya berwarna hitam atau cokelat dan kabel sinyal biasanya berwarna oranye atau kuning. Cara menkoneksikan servo analog dengan arduino cukup mudah, yaitu sbb:
//VCC ke 5v 
//GND ke GND
//Sinyal ke pin digital