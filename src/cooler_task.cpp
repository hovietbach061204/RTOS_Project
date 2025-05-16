#include "cooler_task.h"
#include "defines.h"
#include "sensor_task.h"
#include "software_timer.h"
#include <Arduino.h>

typedef enum {
    COOLER_IDLE,
    COOLER_ACTIVE
} CoolerState;

static CoolerState cooler_state = COOLER_IDLE;

void setup_cooler_leds() {
    pinMode(COOLER_LED1, OUTPUT);
    pinMode(COOLER_LED2, OUTPUT);
    digitalWrite(COOLER_LED1, LOW);
    digitalWrite(COOLER_LED2, LOW);
    Serial.println("[Cooler] LEDs initialized (both OFF).");
}

void cooler_task() {
    Serial.print("[Cooler] State: ");
    Serial.println(cooler_state == COOLER_IDLE ? "IDLE" : "ACTIVE");

    switch(cooler_state) {   
        case COOLER_IDLE:
            Serial.print("[Cooler] Temp check: ");
            Serial.print(temperature);
            Serial.print(" °C (Threshold: ");
            Serial.print(COOLER_THRESHOLD);
            Serial.println(" °C)");

            if (temperature > COOLER_THRESHOLD) {
                digitalWrite(COOLER_LED1, HIGH);
                digitalWrite(COOLER_LED2, LOW);
                Timer_Set(0, 500); // 5s -> 500 ticks of 10ms
                cooler_state = COOLER_ACTIVE;
                Serial.println("[Cooler] COOLING started. LEDs ON. Timer set for 5s.");
            }else{
                digitalWrite(COOLER_LED1, LOW);
                digitalWrite(COOLER_LED2, LOW);
            }
            break;

        case COOLER_ACTIVE:
            if (Timer_IsExpired(0)) {
                cooler_state = COOLER_IDLE;
                Serial.println("[Cooler] Cooling complete. LEDs OFF. Returning to IDLE.");
            } else {
                Serial.println("[Cooler] Cooling in progress... Timer not expired yet.");
            }
            break;
    }
}
