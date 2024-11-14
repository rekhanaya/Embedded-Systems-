#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);  // Ganti alamat HEX jika perlu
Servo myservo1;

int IR1 = 2;           // Sensor inframerah 1 (Masuk)
int IR2 = 4;           // Sensor inframerah 2 (Keluar)
int Slot = 4;          // Jumlah slot parkir yang tersedia

void setup() {
  lcd.begin();
  lcd.backlight();
  
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  
  myservo1.attach(3);
  myservo1.write(100);  // Pintu tertutup (posisi servo pada 100)

  lcd.setCursor(0, 0);
  lcd.print("     ARDUINO    ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING SYSTEM ");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorMasuk = digitalRead(IR1);   // Membaca sensor IR1
  int sensorKeluar = digitalRead(IR2);  // Membaca sensor IR2

  // Jika kendaraan terdeteksi masuk dan ada slot tersedia
  if (sensorMasuk == LOW) {
    if (Slot > 0) {
      myservo1.write(0);  // Buka pintu
      delay(1000);        // Tunggu 1 detik untuk kendaraan lewat
      Slot--;             // Kurangi slot yang tersedia
      myservo1.write(100); // Tutup pintu
      delay(1000);        // Delay agar pintu tertutup dengan benar
    } else {
      lcd.setCursor(0, 0);
      lcd.print("    SORRY :(    ");  
      lcd.setCursor(0, 1);
      lcd.print("  Parking Full  "); 
      delay(3000);
      lcd.clear();
    }
  }

  // Jika kendaraan terdeteksi keluar
  if (sensorKeluar == LOW) {
    myservo1.write(0);  // Buka pintu
    delay(1000);        // Tunggu 1 detik untuk kendaraan lewat
    Slot++;             // Tambah slot yang tersedia
    myservo1.write(100); // Tutup pintu
    delay(1000);        // Delay agar pintu tertutup dengan benar
  }

  // Update tampilan LCD dengan slot yang tersedia
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME!    ");
  lcd.setCursor(0, 1);
  lcd.print("Slot Left: ");
  lcd.print(Slot);
}
