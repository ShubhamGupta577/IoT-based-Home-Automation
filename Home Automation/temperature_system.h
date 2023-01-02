#ifndef TEMPERATURE_SYSTEM_H
#define TEMPERATURE_SYSTEM_H

#define HEATER                5
#define COOLER                4


#define TEMPERATURE_SENSOR    A0


float read_temperature(void);
void init_temperature_system(void);
void cooler_control(bool control);
void heater_control(bool control);
#endif
