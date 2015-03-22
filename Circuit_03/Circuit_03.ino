#include <VirtualWire.h>

uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
char notes[] = "c";
int beats[] = {4};
int tempo = 150;
void allThatJunk()
  {
      int i, duration;
  
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms
    
    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
}
  }
void setup()
{
  w_set_ptt_inverted(true); // Required for RF link modules
vw_setup(300);
vw_set_rx_pin(8);
vw_rx_start();
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
}
void loop()
{
if (vw_get_message(buf, &buflen))
{
switch(buf[0])
{

case 'c':
digitalWrite(7, HIGH);
allThatJunk();
break;
case 'd':
digitalWrite(7, LOW);
allThatJunk();
break;
}
}
}
