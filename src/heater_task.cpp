#include "heater_task.h"
#include "defines.h"
#include "sensor_task.h"
#include <Arduino.h>

void setup_heater_leds()
{
    pinMode(HEATER_LED1, OUTPUT);
    pinMode(HEATER_LED2, OUTPUT);
    digitalWrite(HEATER_LED1, LOW);
    digitalWrite(HEATER_LED2, LOW);
    Serial.println("[Heater] LEDs initialized (both OFF).");
}

void heater_task()
{
    Serial.print("[Heater] Current temp: ");
    Serial.print(temperature);
    Serial.print(" °C -> ");

    if (temperature >= HEATER_WARNING_THRESHOLD)
    {
        // Safe (Green): Both LEDs ON
        digitalWrite(HEATER_LED1, HIGH); // Green
        digitalWrite(HEATER_LED2, HIGH);
        Serial.println("SAFE zone (Green LED).");
    }
    else if (temperature >= HEATER_DANGER_THRESHOLD)
    {
        // Warning (Orange): One LED ON, one OFF
        digitalWrite(HEATER_LED1, HIGH);
        digitalWrite(HEATER_LED2, LOW);
        Serial.println("WARNING zone (Orange LED).");
    }
    else
    {
        // Danger (Red): Both LEDs OFF
        digitalWrite(HEATER_LED1, LOW); // Red
        digitalWrite(HEATER_LED2, HIGH);
        Serial.println("DANGER zone (Red LED).");
    }
}
