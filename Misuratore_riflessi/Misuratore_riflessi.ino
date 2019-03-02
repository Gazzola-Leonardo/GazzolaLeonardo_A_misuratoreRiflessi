const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

int numRandom = 0;
int tempo = 0;
int tempo2 = 0;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
 
void setup() {
  Serial.begin(9600);
  Serial.println("Seriale attiva");
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin); 
  if (buttonState == HIGH) {
    Serial.println(buttonState);
    accendiLed();
  }

}
void accendiLed(){
  numRandom = random(1000, 3000);
  Serial.println("num random");
  Serial.println(numRandom);
  tempo = millis();
  while(true){
    if(numRandom == millis() - tempo){
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      break;
    }
  }
}
