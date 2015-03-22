#include <VirtualWire.h>
#define VW_MAX_MESSAGE_LEN 8
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

const char *on3 = "c";
const char *off3 = "d";
void setup()
{
vw_set_ptt_inverted(true); // Required for RF Link modules
vw_setup(300); // set data speed
vw_set_tx_pin(8);

pinMode(3, INPUT);
}
void loop()
{

if (digitalRead(3)==HIGH)
{
vw_send((uint8_t *)on3, strlen(on3));
vw_wait_tx();
delay(200);
}
if (digitalRead(3)==LOW)
{
vw_send((uint8_t *)off3, strlen(off3));
vw_wait_tx();
delay(200);
}
}
