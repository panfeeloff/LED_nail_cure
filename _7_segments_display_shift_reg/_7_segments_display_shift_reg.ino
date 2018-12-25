/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/
 // 0 = 252 ; 1 = 96 ; 2 = 218 ; 3 = 242 ; 4 = 102 ; 5 = 182 ; 6 = 190 ; 7 = 224 ; 8 = 254 ; 9 = 246
//int latchPin = 4;
//int clockPin = 3;
//int dataPin = 2;
int i = 1; //used for displayed digits
//int number [] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246}; //dec for numbers
int digit = 0;
const int buttonPin = 0;    // the number of the pushbutton pin was 40
const int ledPin = 13;      // the number of the LED pin
const int modulePin = 3;    // that goes to LED module, was 41
const int fanPin = 2;    // goes to fan, was 30


// Variables will change:
int ledState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
int time = 0;                 
long n = 0;
long fantime = 0;            //used add 30 sec to fan time

int D0 = 5;                //Display pins test
int D1 = 6;
int D2 = 7;
int D3 = 8;
int D4 = 9;
int D5 = 10;
int D6 = 11;

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;    // the last time the output pin was toggled
long debounceDelay = 10;    // the debounce time; increase if the output flickers
long lastturnOnTime = 0;        //
long turnOnTime = 1000;    // used for turn on

void setup() 
{
 // pinMode(latchPin, OUTPUT);
 // pinMode(dataPin, OUTPUT);  
 // pinMode(clockPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(modulePin, OUTPUT);
  pinMode (fanPin, OUTPUT);
  pinMode (D0, OUTPUT);
  pinMode (D1, OUTPUT);
  pinMode (D2, OUTPUT);
  pinMode (D3, OUTPUT);
  pinMode (D4, OUTPUT);
  pinMode (D5, OUTPUT);
  pinMode (D6, OUTPUT);
  //Serial.begin(9600);
   
  // set initial LED state
  digitalWrite(ledPin, ledState);
  digitalWrite (modulePin, LOW);
  
}
 
void loop() 
{
  
  //===== BUTTON PART======
  
   // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
    lastturnOnTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is LOW
      if (buttonState == LOW)    //action at button release
    
      {
       // ledState = !ledState;  //REMOVE LATER

        if (i<=8) i = i+1;
        else i = 1;
      }
        //else if (i>9) i = 0;  //original
        else if (buttonState == HIGH){
          lastturnOnTime = millis();
        
        }
            
      }
    }
     
  Serial.println(buttonState); 
  time = (millis() - lastturnOnTime);
  if (reading == LOW) time = 0;

   if (reading == HIGH && time > turnOnTime) {
 


  
  //=====Turn light on
  
 digitalWrite(modulePin, HIGH); 
 digitalWrite (fanPin, HIGH);
 delay (i*10000L); //normal mode
 digitalWrite(modulePin, LOW);
 fantime = millis() + i*10000L;
 i = 0;      
 }
 
 
 if (millis() >= fantime) {
digitalWrite (fanPin, LOW);
 fantime = 0;
 }
  
  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
  //Serial.println(fanPin);
// ========DISPLAY PART=====  

//========atmega328 pins
// ZERO
if (i==0)
{
digitalWrite (D0, HIGH);
digitalWrite (D1, HIGH);
digitalWrite (D2, HIGH);
digitalWrite (D3, HIGH);
digitalWrite (D4, HIGH);
digitalWrite (D5, HIGH);
digitalWrite (D6, LOW);
}

//ONE
if (i==1)
{
digitalWrite (D0, LOW);
digitalWrite (D1, HIGH);
digitalWrite (D2, HIGH);
digitalWrite (D3, LOW);
digitalWrite (D4, LOW);
digitalWrite (D5, LOW);
digitalWrite (D6, LOW);
}
//TWO
if (i==2)
{
digitalWrite (D0, HIGH);
digitalWrite (D1, HIGH);
digitalWrite (D2, LOW);
digitalWrite (D3, HIGH);
digitalWrite (D4, HIGH);
digitalWrite (D5, LOW);
digitalWrite (D6, HIGH);
}
//THREE
if (i==3)
{
digitalWrite (D0, HIGH);
digitalWrite (D1, HIGH);
digitalWrite (D2, HIGH);
digitalWrite (D3, HIGH);
digitalWrite (D4, LOW);
digitalWrite (D5, LOW);
digitalWrite (D6, HIGH);
}

//FOUR
if (i==4)
{
digitalWrite (D0, LOW);
digitalWrite (D1, HIGH);
digitalWrite (D2, HIGH);
digitalWrite (D3, LOW);
digitalWrite (D4, LOW);
digitalWrite (D5, HIGH);
digitalWrite (D6, HIGH);
}
//FIVE
if (i==5)
{
digitalWrite (D0, HIGH);
digitalWrite (D1, LOW);
digitalWrite (D2, HIGH);
digitalWrite (D3, HIGH);
digitalWrite (D4, LOW);
digitalWrite (D5, HIGH);
digitalWrite (D6, HIGH);
}
//SIX
if (i==6)
{
digitalWrite (D0, HIGH);
digitalWrite (D1, LOW);
digitalWrite (D2, HIGH);
digitalWrite (D3, HIGH);
digitalWrite (D4, HIGH);
digitalWrite (D5, HIGH);
digitalWrite (D6, HIGH);
}
//SEVEN
if (i==7)
{
digitalWrite (D0, HIGH);
digitalWrite (D1, HIGH);
digitalWrite (D2, HIGH);
digitalWrite (D3, LOW);
digitalWrite (D4, LOW);
digitalWrite (D5, LOW);
digitalWrite (D6, LOW);
}
//EIGHT
if (i==8)
{
digitalWrite (D0, HIGH);
digitalWrite (D1, HIGH);
digitalWrite (D2, HIGH);
digitalWrite (D3, HIGH);
digitalWrite (D4, HIGH);
digitalWrite (D5, HIGH);
digitalWrite (D6, HIGH);
}

//NINE
if (i==9)
{
digitalWrite (D0, HIGH);
digitalWrite (D1, HIGH);
digitalWrite (D2, HIGH);
digitalWrite (D3, HIGH);
digitalWrite (D4, LOW);
digitalWrite (D5, HIGH);
digitalWrite (D6, HIGH);
}

}






