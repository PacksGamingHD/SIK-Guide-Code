#include <VirtualWire.h>

uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
const int buzzerPin = 9;
char notes[] = "c";
int beats[] = {4};
int tempo = 150;
const int songLength = 1;
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
  Serial.begin(9600);
vw_set_ptt_inverted(true); // Required for RF link modules
vw_setup(300);
vw_set_rx_pin(9);
vw_rx_start();
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
Serial.println("void setup ran successfully");
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
break;
}
}
Serial.println("void loop ran successfully");
}
int frequency(char note) 
{
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.
  
  int i;
  const int numNotes = 8;  // number of notes we're storing
  
  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  
  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.
  
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}
