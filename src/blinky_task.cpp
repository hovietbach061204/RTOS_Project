#include <Arduino.h>

#define LED_ON 0
#define LED_OFF 1
#define INIT 2

static int state = INIT;

void blinky_task(void) {
    switch (state) {
        case INIT:
            pinMode(GPIO_NUM_48, OUTPUT);
            state = LED_ON;
            digitalWrite(GPIO_NUM_48, 1);
            break;

        case LED_ON:
            state = LED_OFF;
            digitalWrite(GPIO_NUM_48, 0);
            break;

        case LED_OFF:
            state = LED_ON;
            digitalWrite(GPIO_NUM_48, 1);
            break;
    }
}