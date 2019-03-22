#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int buttonPin = 13;    
const int ledPin =  12;   
const int buzzerPin = 8;

int numRandom = 0;
int tempo = 0;
int tempo2 = 0;       
 
void setup() {
  //Serial.begin(9600);
  //Serial.println("Seriale attiva");
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Benvenuto!");
}

void loop() {
  while(digitalRead(buttonPin) == LOW);
  accendiLed();
  tempoLed();
  tone(buzzerPin, 1000, 500);
  delay(1000);
  while(digitalRead(buttonPin) == HIGH);
}
void accendiLed(){
  numRandom = random(1000, 3000);
  tempo = millis();
  while(numRandom != millis() - tempo);
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  while(numRandom == millis() - tempo);
}
void tempoLed(){
  while(digitalRead(buttonPin) == LOW);
  lcd.begin(16, 2);
  lcd.print(millis() - numRandom - tempo);
  while(digitalRead(buttonPin) == HIGH);
}
