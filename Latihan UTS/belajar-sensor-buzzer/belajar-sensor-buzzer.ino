// Positif (+): Pin digital (misal: pin 3 di Arduino)
// Negatif (-): GND

int buzzer = 3;

void setup() {
    pinMode(buzzer, OUTPUT);
}

void loop() {
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
}
