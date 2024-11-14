// belajar sensor suara

const int soundSensorPin = A0; //pin digital untuk sensor suara
const int ledPin = 13;        //pin untuk led

void setup() {
  // inisialisasi pin sensor suara sebagai input
  // pinMode(soundSensorPin, INPUT);

  // inisialisasi pin led sebagai output
  pinMode(ledPin, OUTPUT);

  // memulai komunikasi serial
  Serial.begin(9600);
}

void loop() {
  // membaca nilai dari sensor suara
  int soundValue = analogRead(soundSensorPin);

  // menampilkan nilai ke serial monitor
  Serial.println(soundValue);

  // jika suara terdeteksi (nilai HIGH)
  if(soundValue == HIGH) {
    digitalWrite(ledPin, HIGH); //nyalakan led
  } else {
    digitalWrite(ledPin, LOW); //nyalakan led
  }

  // delay untuk stabilitas
  delay(100);
}
