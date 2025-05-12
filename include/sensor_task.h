#ifndef SENSOR_TASK_H
#define SENSOR_TASK_H
#include <DHT20.h>

extern DHT20 dht20; 
extern float temperature;
extern float humidity;

void sensor_task(void);

#endif
