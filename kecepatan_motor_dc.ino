#define potensio A0
#define ENA 3
#define IN1 0
#define IN2 1
#define led 7
#define button_hidup 13
#define button_mati 12

int kecepatan=0;

void setup() {
  pinMode(potensio,INPUT);
  pinMode(button_hidup,INPUT_PULLUP);
  pinMode(button_mati,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
  analogWrite(ENA,0);
  delay(500);
}


void loop() {
  kecepatan=analogRead(potensio);
  kecepatan=map(kecepatan,0,1023,0,255);
  
  if(digitalRead(button_hidup)==LOW){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA,kecepatan);
    digitalWrite(led,HIGH);
  }
  else if(digitalRead(button_mati)==LOW){
    analogWrite(ENA,0);
    digitalWrite(led,LOW);
  }
}
