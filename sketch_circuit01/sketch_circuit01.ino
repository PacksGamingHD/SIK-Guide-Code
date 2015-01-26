int timeDelay[] = {500,1000,1350};

void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  int index;
  for(index = 0; index <= 2; index++);
  {
  turnLED(timeDelay[index]);
  }
}

void turnLED(int timeDelay)
{
  digitalWrite(13, LOW);
  
  delay(timeDelay);
  
  digitalWrite(13, HIGH);
  
  delay(timeDelay);
}
