int led1 = 4;
int led2 = 8;
int led3 = 11;
int led4 = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);
  pinMode(led3, OUTPUT);
  digitalWrite(led3, LOW);
  pinMode(led4, OUTPUT);
  digitalWrite(led4, LOW);
  delay(50); //satuan secon
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1, HIGH);
  delay(70);
  digitalWrite(led1, LOW);
  delay(70);
  digitalWrite(led2, HIGH);
  delay(70);
  digitalWrite(led2, LOW);
  delay(70);
  digitalWrite(led3, HIGH);
  delay(70);
  digitalWrite(led3, LOW);
  delay(70);
  digitalWrite(led4, HIGH);
  delay(70);
  digitalWrite(led4, LOW);
  delay(70);
  digitalWrite(led3, HIGH);
  delay(70);
  digitalWrite(led3, LOW);
  delay(70);
  digitalWrite(led2, HIGH);
  delay(70);
  digitalWrite(led2, LOW);
  delay(70);
}
