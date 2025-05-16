#include "humidifier_task.h"
#include "defines.h"
#include "sensor_task.h"
#include "software_timer.h"
#include <Arduino.h>

#define INIT 0
#define READY 1
#define GREEN 2
#define YELLOW 3
#define RED 4

// Timing constants
static const int S = 1;
static const int green = 500;
static const int yellow = 300;
static const int red = 200;

static int q = READY;

void setup_humidifier_leds()
{
    pinMode(HUMIDIFIER_LED1, OUTPUT);
    pinMode(HUMIDIFIER_LED2, OUTPUT);
    digitalWrite(HUMIDIFIER_LED1, LOW);
    digitalWrite(HUMIDIFIER_LED2, LOW);
    Serial.println("[Humidifier] LEDs initialized (both OFF).");
}

void humidifier_task()
{
    switch (q)
    {
    case INIT:
        q = READY;
        digitalWrite(HUMIDIFIER_LED1, LOW);
        digitalWrite(HUMIDIFIER_LED2, LOW);
        break;

    case READY:
        if (humidity < HUMIDIFIER_THRESHOLD)
        {
            q = GREEN;
            Timer_Set(S, green);
            digitalWrite(HUMIDIFIER_LED1, HIGH);
            digitalWrite(HUMIDIFIER_LED2, LOW);
        }
        break;

    case GREEN:
        if (!Timer_IsExpired(S))
            return;

        q = YELLOW;
        Timer_Set(S, yellow);
        digitalWrite(HUMIDIFIER_LED1, LOW);
        digitalWrite(HUMIDIFIER_LED2, HIGH);
        break;

    case YELLOW:
        if (!Timer_IsExpired(S))
            return;

        q = RED;
        Timer_Set(S, red);
        digitalWrite(HUMIDIFIER_LED1, HIGH);
        digitalWrite(HUMIDIFIER_LED2, HIGH);
        break;

    case RED:
        if (Timer_IsExpired(S))
        {
            if (humidity < HUMIDIFIER_THRESHOLD)
            {
                q = GREEN;
                Timer_Set(S, green);
                digitalWrite(HUMIDIFIER_LED1, HIGH);
                digitalWrite(HUMIDIFIER_LED2, LOW);
            }else{
                q = INIT;
            }
        }
        break;
    }
}
