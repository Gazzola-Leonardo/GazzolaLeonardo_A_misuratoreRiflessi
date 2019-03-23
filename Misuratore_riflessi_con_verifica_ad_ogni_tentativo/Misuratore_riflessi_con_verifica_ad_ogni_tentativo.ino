#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int buttonPin = 13;    
const int ledPin =  12;   
const int buzzerPin = 11;
const int rgbRosso = 8;
const int rgbVerde = 9;
const int rgbBlu = 10;

long numRandom = 0;
long ledTempo = 0;  
long buzzerTempo = 0;  
 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(rgbRosso, OUTPUT);
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbBlu, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Benvenuto!");
  lcd.setCursor(0, 1);
  lcd.print("Premi il bottone");
  digitalWrite(rgbRosso, LOW);
  digitalWrite(rgbVerde, LOW);
}

void loop() {
  accendiLed();
  accendiBuzzer();
  controlloFinale();
  azzera();
}

void accendiLed(){
  while(digitalRead(buttonPin) == LOW){};
  while(digitalRead(buttonPin) == HIGH){};
  lcd.begin(16, 2);
  lcd.print("Attendi...");
  numRandom = random(1000, 2000) + millis();
  while(numRandom > millis());
  digitalWrite(ledPin, HIGH);
  tempoLed();
}
void accendiBuzzer(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Attendi...");
  numRandom = random(1000, 2000) + millis();
  while(numRandom > millis());
  tone(buzzerPin, 1000, 300);
  tempoBuzzer();
}
void tempoLed(){
  while(digitalRead(buttonPin) == LOW);
  digitalWrite(ledPin, LOW);
  numRandom = millis() - numRandom;
  ledTempo = numRandom;
  lcd.setCursor(0, 0);
  lcd.print("Led: ");
  lcd.print(ledTempo);
  lcd.print(" ms");
  controllo();
  delay(1500);
  while(digitalRead(buttonPin) == HIGH);
}
void tempoBuzzer(){
  while(digitalRead(buttonPin) == LOW);
  numRandom = millis() - numRandom;
  buzzerTempo = numRandom;
  lcd.setCursor(0, 0);
  lcd.print("Buzzer: ");
  lcd.print(buzzerTempo);
  lcd.print(" ms");
  controllo();
  while(digitalRead(buttonPin) == HIGH);
}
void controllo(){
  if(numRandom < 500){
    lcd.setCursor(0, 1);
    lcd.print("> Passato <");
  }else{
    lcd.setCursor(0, 1);
    lcd.print("> NON passato <");
  }
}
void controlloFinale(){
  //while(digitalRead(buttonPin) == LOW);
  delay(2000);
  lcd.clear();
  if(buzzerTempo <= 500 && ledTempo <= 500){
    lcd.setCursor(0, 0);
    lcd.print("Test passato!!");
    digitalWrite(rgbVerde, HIGH);
  }else{
    lcd.setCursor(0, 0);
    lcd.print("Non passato");
    digitalWrite(rgbRosso, HIGH);
  }
  long media = round((ledTempo + buzzerTempo) / 2);
  lcd.setCursor(0, 1);
  lcd.print("Media: ");
  lcd.print(media); //la media viene stampata solo per far conoscere all'utente la sua media
  lcd.print(" ms");
  while(digitalRead(buttonPin) == HIGH){};
}
void azzera(){
  while(digitalRead(buttonPin) == HIGH){};
  while(digitalRead(buttonPin) == LOW){};
  digitalWrite(rgbRosso, LOW);
  digitalWrite(rgbVerde, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Azzeramento. ");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Azzeramento..");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Azzeramento...");
  delay(1000);
  setup();
  while(digitalRead(buttonPin) == HIGH){};
}
