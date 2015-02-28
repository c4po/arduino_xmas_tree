
// set pin numbers:

int ledPins[]= {9,12,6,11,4,5,13,7,10,8};
int pinCount=10;


// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 400;           // interval at which to blink (milliseconds)



int ledon=0;

void setup() {
// set the digital pin as output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);      
  }  
}


void reset(boolean level)
{
  for (int thisPin=0; thisPin<pinCount;thisPin++) {
      digitalWrite(ledPins[thisPin], level);
  }  
}

void l0(int repeat)
{
  for (int r=0;r<repeat;r++){
    reset(HIGH);
    delay(interval);
    reset(LOW);
    delay(interval/2);
  }
}

void l1(int repeat)
{
  for (int r=0;r<repeat;r++){
    reset(LOW);
    for (int thisPin=0; thisPin<pinCount;thisPin++) {
        digitalWrite(ledPins[thisPin], HIGH);
        delay(interval);
        digitalWrite(ledPins[thisPin], LOW);
    }
  }
}

void l2(int repeat)
{
  for (int r=0;r<repeat;r++){
    reset(LOW);
    for (int thisPin=0; thisPin<pinCount;thisPin++) {
        digitalWrite(ledPins[thisPin], HIGH);
        delay(interval);
    }
  }
}

void l3(int repeat, int length)
{
  for (int r=0;r<repeat;r++){
    reset(LOW);
    for (int thisPin=0; thisPin<length;thisPin++) {
      for (int pin=thisPin; pin<pinCount; pin+=length) {
        digitalWrite(ledPins[pin], HIGH);
      }
      delay(interval);
      reset(LOW);
    }
  }
}

void l4(int repeat, int length)
{
  for (int r=0;r<repeat;r++){
    reset(LOW);
    for (int thisPin=0; thisPin<length;thisPin++) {
      for (int pin=thisPin; pin<pinCount/2; pin+=length) {
        digitalWrite(ledPins[pin], HIGH);
        digitalWrite(ledPins[pinCount-pin-1], HIGH);
      }
        delay(interval);
        reset(LOW);
    }
  }
}

void l5(int repeat)
{
  for (int r=0;r<repeat;r++){
    reset(LOW);
    for (int thisPin=0; thisPin<pinCount/2; thisPin++) {
        digitalWrite(ledPins[thisPin], HIGH);
        digitalWrite(ledPins[pinCount-thisPin-1], HIGH);
        delay(interval);
      }
      reset(LOW);
      delay(interval);
      l0(3);
  }
}

void l6(int repeat)
{
  for (int r=0;r<repeat;r++){
    reset(LOW);
    for (int thisPin=0; thisPin<pinCount/2; thisPin++) {
      for (int pin=thisPin; pin>=0; pin--) {
        digitalWrite(ledPins[pin], HIGH);
        digitalWrite(ledPins[pinCount-pin-1], HIGH);
        delay(interval);
      }
    reset(LOW);
    delay(interval);
  }
  delay(interval);
  reset(LOW);
  }
}

void l7(int repeat)
{
  int pin=0;
  for (int r=0;r<repeat;r++){
    for (int i=0; i<pinCount;i++) {
      pin= random(10);
      digitalWrite(ledPins[pin], HIGH);
      delay(interval);
    }
    reset(LOW);
    delay(interval);
  }
}



void loop()
{
  int randNumber = random(10);
  reset(LOW);
  switch (randNumber) {
    case 0:
      l0(5);
      break;
    case 1:
      l1(5);
      break;
    case 2:
      l2(5);
      break;
    case 3:
      l3(5,3);
      break;
    case 4:
      l3(5,2);
      break;
    case 5:
      l4(5,3);
      break;
    case 6:
      l5(5);
      break;
    case 7:
      l6(5);
      break;
    case 8:
      l7(5);
      break;
    case 9:
      l4(5,2);
      break;
    default: 
      l5(3);
  }  
}

