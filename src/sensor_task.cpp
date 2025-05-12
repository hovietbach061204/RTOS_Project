#include "sensor_task.h"
#include <Arduino.h>
#include "defines.h"
#include <DHT20.h>

DHT20 dht20;


float temperature = 0.0;
float humidity = 0.0;

void sensor_task() {
    dht20.read();

    temperature = dht20.getTemperature();
    humidity = dht20.getHumidity();

    Serial.print("Temp: "); Serial.print(temperature);
    Serial.print(" °C | Humidity: "); 
    Serial.print(humidity); 
    Serial.println(" %");
}
