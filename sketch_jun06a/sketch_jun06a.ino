void setup()
{
  analogReadResolution(12);//Allows the values to range from 0 to 4096. 
                           //If this wasn't done, the values would range from 0 to 1024.
  Serial.begin(9600); // initialize serial communication 
  pinMode(69, OUTPUT); // sets the LED pins on the LaunchPad to output
  pinMode(68, OUTPUT);
  pinMode(65, OUTPUT);
  pinMode(64, OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(39, OUTPUT);
  
}

/* In the loop section we will read the photoresistor analog value
 * then we will use the map() and constrain() functions to adjust the 
 * range for PWM. When the photoresistor is dark the LED will turn on, 
 * you can cover the photoresistor with your hand to block out light.
 */
void loop()
{
  int lightLevel = analogRead(59); // Read the light level from analog pin 59
  Serial.println(lightLevel); // Print the analog value to Serial
  // adjust the value 0 to max resolution to span 0 to 255
  lightLevel = map(lightLevel, 0, 4096, 0, 255); //sets the value between 0-4096 
                                                 //to a proportional value between 0-255
  lightLevel = constrain(lightLevel, 0, 255); // constrain values between 0-255
  if (lightLevel < 26)
  {
    /* If the photo resistor senses light at a value below 26,
    *  the first LED will adjust 
    *  accordingly through analogWrite, while the other LEDs reamin off.
    */
    analogWrite(69, map(lightLevel, 0, 26, 0, 255));
    digitalWrite(68, LOW);
    digitalWrite(65, LOW);
    digitalWrite(64, LOW);
    digitalWrite(53, LOW);
    digitalWrite(52, LOW);
    digitalWrite(48, LOW);
    digitalWrite(47, LOW);
    digitalWrite(40, LOW);
    digitalWrite(39, LOW);
  }
  else if (lightLevel < 51)
  {
    /* If the phott resistor senses light at a value below 51,
    *  the first LED will be digitally on, 
    *  and the second LED will adjust 
    *  accordingly through analogWrite, while the other LEDs reamin off.
    */
    digitalWrite(69, HIGH);
    analogWrite(68, map(lightLevel-26, 0, 26, 0, 255));
    digitalWrite(65, LOW);
    digitalWrite(64, LOW);
    digitalWrite(53, LOW);
    digitalWrite(52, LOW);
    digitalWrite(48, LOW);
    digitalWrite(47, LOW);
    digitalWrite(40, LOW);
    digitalWrite(39, LOW);
  }
  else if (lightLevel < 76)
  {
    /* If the photo resistor senses light at a value below 76, 
    *  the first two LEDs will be digitally on, 
    *  and the third LED will adjust 
    *  accordingly through analogWrite, while the other LEDs reamin off.
    *  The pattern continues for all LEDs until full brightness is reached,
    *  which occurs when the photo resistor 
    */
    digitalWrite(69, HIGH);
    digitalWrite(68, HIGH);
    analogWrite(65, map(lightLevel-51, 0, 26, 0, 255));
    digitalWrite(64, LOW);
    digitalWrite(53, LOW);
    digitalWrite(52, LOW);
    digitalWrite(48, LOW);
    digitalWrite(47, LOW);
    digitalWrite(40, LOW);
    digitalWrite(39, LOW);
  }
   else if (lightLevel < 102)
  {
    digitalWrite(69, HIGH);
    digitalWrite(68, HIGH);
    digitalWrite(65, HIGH);
    analogWrite(64, map(lightLevel-76, 0, 26, 0, 255));
    digitalWrite(53, LOW);
    digitalWrite(52, LOW);
    digitalWrite(48, LOW);
    digitalWrite(47, LOW);
    digitalWrite(40, LOW);
    digitalWrite(39, LOW);
  }
    else if (lightLevel < 127)
  {
    digitalWrite(69, HIGH);
    digitalWrite(68, HIGH);
    digitalWrite(65, HIGH);
    digitalWrite(64, HIGH);
    analogWrite(53, map(lightLevel-102, 0, 26, 0, 255));
    digitalWrite(52, LOW);
    digitalWrite(48, LOW);
    digitalWrite(47, LOW);
    digitalWrite(40, LOW);
    digitalWrite(39, LOW);
  }
  else if (lightLevel < 153)
  {
    digitalWrite(69, HIGH);
    digitalWrite(68, HIGH);
    digitalWrite(65, HIGH);
    digitalWrite(64, HIGH);
    digitalWrite(53, HIGH);
    analogWrite(52, map(lightLevel-127, 0, 26, 0, 255));
    digitalWrite(48, LOW);
    digitalWrite(47, LOW);
    digitalWrite(40, LOW);
    digitalWrite(39, LOW);
  }
   else if (lightLevel < 178)
  {
    digitalWrite(69, HIGH);
    digitalWrite(68, HIGH);
    digitalWrite(65, HIGH);
    digitalWrite(64, HIGH);
    digitalWrite(53, HIGH);
    digitalWrite(52, HIGH);
    analogWrite(48, map(lightLevel-153, 0, 26, 0, 255));
    digitalWrite(47, LOW);
    digitalWrite(40, LOW);
    digitalWrite(39, LOW);
  }
   else if (lightLevel < 204)
  {
    digitalWrite(69, HIGH);
    digitalWrite(68, HIGH);
    digitalWrite(65, HIGH);
    digitalWrite(64, HIGH);
    digitalWrite(53, HIGH);
    digitalWrite(52, HIGH);
    digitalWrite(48, HIGH);
    analogWrite(47, map(lightLevel-178, 0, 26, 0, 255));
    digitalWrite(40, LOW);
    digitalWrite(39, LOW);
  }
  else if (lightLevel < 229)
  {
    digitalWrite(69, HIGH);
    digitalWrite(68, HIGH);
    digitalWrite(65, HIGH);
    digitalWrite(64, HIGH);
    digitalWrite(53, HIGH);
    digitalWrite(52, HIGH);
    digitalWrite(48, HIGH);
    digitalWrite(47, HIGH);
    analogWrite(40, map(lightLevel-204, 0, 26, 0, 255));
    digitalWrite(39, LOW);
  }
  else if (lightLevel < 255)
  {
    digitalWrite(69, HIGH);
    digitalWrite(68, HIGH);
    digitalWrite(65, HIGH);
    digitalWrite(64, HIGH);
    digitalWrite(53, HIGH);
    digitalWrite(52, HIGH);
    digitalWrite(48, HIGH);
    digitalWrite(47, HIGH);
    digitalWrite(40, HIGH);
    analogWrite(39, map(lightLevel-229, 0, 26, 0, 255));
  }
    
   
  delay(100);//gives the Luanchpad time to complete the code
}
