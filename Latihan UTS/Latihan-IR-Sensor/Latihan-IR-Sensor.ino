//////////// LATIHAN IR SENSOR /////////////////////

int sensorPin = 2;
int ledPin = 13; 

void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin,LOW); 
  pinMode (sensorPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorNilai = digitalRead(sensorPin);
  if (sensorNilai == 0)
  {
    Serial.println("Objek Terdeteksi!");
    digitalWrite(ledPin, HIGH);
    delay(1000);
  } 
  else
  {
    digitalWrite(ledPin, LOW);
    delay(1000); 
    Serial.println("Objek TidakTerdeteksi!");
    delay(1000);
  }
}