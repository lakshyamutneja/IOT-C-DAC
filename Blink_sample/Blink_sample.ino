/*
  Blink
  The basic Energia example.
  Turns on an LED on for one second, then off for one second, repeatedly.
  Change the LED define to blink other LEDs.
  
  Hardware Required:
  * LaunchPad with an LED
  
  This example code is in the public domain.
*/

// most launchpads have a red LED
#define LED RED_LED

//see pins_energia.h for more LED definitions
//#define LED GREEN_LED
  
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(77, OUTPUT); 
  pinMode(78, OUTPUT);
      
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(77, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(77, LOW);
  // wait for a second
  delay(1000);
  digitalWrite(78, HIGH);
  delay(1000);
  digitalWrite(78, LOW);
  // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
