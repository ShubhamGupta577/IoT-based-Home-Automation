#include "ldr.h"
#include "Arduino.h"
#include "main.h"

void init_ldr(void)
{
   pinMode(GARDEN_LIGHT, OUTPUT);
   
}
unsigned int input;
void brightness_control(void)
{
  input= analogRead(LDR_SENSOR);

  input=(1023-input)/4;

  analogWrite(GARDEN_LIGHT,input);
  delay(100);
}
