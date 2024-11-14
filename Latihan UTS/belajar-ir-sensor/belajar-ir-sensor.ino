// VCC: 5V (koneksikan ke 5V di Arduino)
// GND: Ground
// OUT: Pin digital (misal: pin 2 di Arduino)

int sensorIR = 2;
int state = 0;

void setup() {
    pinMode(sensorIR, INPUT);
    Serial.begin(9600);
}

void loop() {
    state = digitalRead(sensorIR);
    if (state == HIGH) {
        Serial.println("Object detected");
    } else {
        Serial.println("No object");
    }
    delay(1000);
}
