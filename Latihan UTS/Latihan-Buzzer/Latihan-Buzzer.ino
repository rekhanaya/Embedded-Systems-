int led1 = 13;
int led2 = 11;
int led3 = 9;
int irsensor = 7;
int delai=150;
int const buzzer=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT); // wajib
  digitalWrite(led1, LOW); //wajib
  delay(100); //satuan milisecond

  pinMode(led2,OUTPUT);
  digitalWrite(led2, LOW);
  delay(100);

  pinMode(led3,OUTPUT);
  digitalWrite(led3, LOW);
  delay(100);

  pinMode(irsensor, INPUT);
  pinMode(buzzer, OUTPUT);
  

}

void loop() {

  int nbaca=digitalRead(irsensor);
  if(nbaca==0)
  {
  

  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  //digitalWrite(led4, LOW);
  tone(buzzer, 100);
  delay(100);

  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  //digitalWrite(led4, LOW);
  tone(buzzer, 400);
  delay(100);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  //digitalWrite(led4, LOW);
  tone(buzzer, 700);
  delay(100);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  //digitalWrite(led4, HIGH);
  tone(buzzer, 1000);
  delay(100);

//INI BIAR BULAK BALIK
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  //digitalWrite(led4, LOW);
  tone(buzzer, 10000);
  delay(100);

  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  //digitalWrite(led4, LOW);
  tone(buzzer,50000);
  delay(100);
  

  }
  else{
    noTone(buzzer);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    delay(100);
  }
  // put your main code here, to run repeatedly:

}
