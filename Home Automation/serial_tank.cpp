#include "serial_tank.h"
#include "Arduino.h"
#include "main.h"

unsigned int volume_value;
unsigned char valueh, valuel;

void init_serial_tank(void) 
{
    Serial.begin(19200);
    Serial.write(0xFF); //Synchronize the Communication
    Serial.write(0xFF);
    Serial.write(0xFF);   
}

//To read volume of water in Serial Tank
unsigned int volume(void)
{
  Serial.write(VOLUME);
  while(!Serial.available());
    valueh=Serial.read();
  while(!Serial.available());
    valuel=Serial.read();

  volume_value=(valueh<<8)|valuel;

  return volume_value;
}
void enable_inlet(void)
{
  Serial.write(INLET_VALVE);
  Serial.write(ENABLE);    
}  
void disable_inlet(void)
{
  Serial.write(INLET_VALVE);
  Serial.write(DISABLE);
}  
void enable_outlet(void)
{  
  Serial.write(OUTLET_VALVE);
  Serial.write(ENABLE);
    
}
void disable_outlet(void)
{  
  Serial.write(OUTLET_VALVE);
  Serial.write(DISABLE);
    
}
