#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int buttonPin = 13;    
const int ledPin =  12;   
const int buzzerPin = 11;
const int rgbRosso = 8;
const int rgbVerde = 9;
const int rgbBlu = 10;

double numRandom = 0;
int ledTempo = 0;  
int buzzerTempo = 0;  
 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(rgbRosso, OUTPUT);
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbBlu, OUTPUT);
  azzera();
}

void loop() {
  while(digitalRead(buttonPin) == LOW);
  while(digitalRead(buttonPin) == HIGH);
  accendiLed();
  tempoLed();
  accendiBuzzer();
  tempoBuzzer();
  calcolaMedia();
  while(digitalRead(buttonPin) == HIGH);
  while(digitalRead(buttonPin) == LOW);
  azzera();
  while(digitalRead(buttonPin) == HIGH);
}
void accendiLed(){
  lcd.begin(16, 2);
  lcd.print("Attendi...");
  numRandom = random(1000, 2000) + millis();
  while(numRandom > millis());
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
}
void accendiBuzzer(){
  lcd.setCursor(0, 1);
  lcd.print("Attendi...");
  numRandom = random(1000, 2000) + millis();
  while(numRandom > millis());
  tone(buzzerPin, 1000, 300);
}
void tempoLed(){
  while(digitalRead(buttonPin) == LOW);
  lcd.begin(16, 2);
  numRandom = millis() - numRandom;
  ledTempo = numRandom;
  lcd.print("Led: ");
  lcd.print(ledTempo);
  lcd.print(" ms");
  while(digitalRead(buttonPin) == HIGH);
}
void tempoBuzzer(){
  while(digitalRead(buttonPin) == LOW);
  lcd.setCursor(0, 1);
  numRandom = millis() - numRandom;
  buzzerTempo = numRandom;
  lcd.print("Buzzer: ");
  lcd.print(buzzerTempo);
  lcd.print(" ms");
  while(digitalRead(buttonPin) == HIGH);
}
void calcolaMedia(){
  while(digitalRead(buttonPin) == LOW);
  lcd.clear();
  double media = round((ledTempo + buzzerTempo) / 2);
  lcd.begin(16, 2);
  lcd.print("Media: ");
  lcd.print(media);
  lcd.print(" ms");
  lcd.setCursor(0, 1);
  if(media < 600){
    lcd.print("Test passato!!");
    digitalWrite(rgbVerde, HIGH);
  }
  else{
    lcd.print("Non superato");
    digitalWrite(rgbRosso, HIGH);
  }
  while(digitalRead(buttonPin) == HIGH);
}
void azzera(){
  lcd.begin(16, 2);
  lcd.print("Benvenuto!");
  lcd.setCursor(0, 1);
  lcd.print("Premi il bottone");
  digitalWrite(rgbRosso, LOW);
  digitalWrite(rgbVerde, LOW);
}
