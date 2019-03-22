#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int buttonPin = 13;    
const int ledPin =  12;     

int numRandom = 0;
int tempo = 0;
int tempo2 = 0;
int buttonState = 0;         
 
void setup() {
  //Serial.begin(9600);
  //Serial.println("Seriale attiva");
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  lcd.print("Benvenuto!");
}

void loop() {
  buttonState = digitalRead(buttonPin); 
  if (buttonState == HIGH) {
    //Serial.println(buttonState);
    accendiLed();
    tempoLed();
  }
  
}
void accendiLed(){
  numRandom = random(1000, 5000) + millis();
  //Serial.println("num random");
  //Serial.println(numRandom);
  tempo = tempo + millis();
  while(true){
    if(numRandom == millis() - tempo){
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
      break;
    }
  }
}
void tempoLed(){
  while(true)
  {
    buttonState = digitalRead(buttonPin); 
    if(buttonState == HIGH){
      lcd.begin(16, 2);
      lcd.print(millis() - numRandom);
      //Serial.println(millis() - numRandom);
      break;      
    }
  }
}
