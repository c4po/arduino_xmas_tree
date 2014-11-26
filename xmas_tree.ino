
// set pin numbers:

int ledPins[]= {13,10,11,12,4,5,6,7};
int pinCount=8;


// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 2000;           // interval at which to blink (milliseconds)

byte pattern = B00000001;


int ledon=0;

void setup() {
// set the digital pin as output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);      
  }  
}

void loop()
{


    for (int thisPin=0; thisPin<pinCount;thisPin++) {
      digitalWrite(ledPins[thisPin], LOW);
    }

    for (int thisPin=0; thisPin<pinCount;thisPin++) {
      delay(500);
      digitalWrite(ledPins[thisPin], HIGH);
    }
  delay(2000);
  for (int i=0; i<5; i++) {    
    for (int thisPin=0; thisPin<pinCount;thisPin++) {
      digitalWrite(ledPins[thisPin], LOW);
    }
    delay(500);
    for (int thisPin=0; thisPin<pinCount;thisPin++) {
      digitalWrite(ledPins[thisPin], HIGH);
    }    
    delay(500);
  }
  delay(1000);
  for (int thisPin=0; thisPin<pinCount;thisPin++) {
   delay(500);
   digitalWrite(ledPins[thisPin], LOW);
  }  
}

