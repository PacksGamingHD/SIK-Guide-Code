/**
 * Custom Circuit_01 Code
 * © 2015 PacksCoding
 */

int timeDelay[] = {500,1000,1350,350}; // Create array

void setup() // Setup the pin
{
  pinMode(13, OUTPUT);
}

void loop() // Start loop
{
  int index;
  for(index = 0; index <= 3; index++);
  {
  turnLED(timeDelay[index]);
  }
}

void turnLED(int timeDelay) // Function
{
  digitalWrite(13, LOW);
  
  delay(timeDelay);
  
  digitalWrite(13, HIGH);
  
  delay(timeDelay);
}
