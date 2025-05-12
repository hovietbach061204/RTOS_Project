#include "software_timer.h"
#include <Arduino.h>

#define MAX_TIMERS 10

static int timer_counter[MAX_TIMERS];
static int timer_flag[MAX_TIMERS];

void Timer_Set(int index, int value) {
    if (index < MAX_TIMERS) {
        timer_counter[index] = value;
        timer_flag[index] = 0;
    }
}

int Timer_IsExpired(int index) {
    if (index < MAX_TIMERS && timer_flag[index]) {
        timer_flag[index] = 0;
        return 1;
    }
    return 0;
}

void Timer_Run(void) {
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (timer_counter[i] > 0) {
            timer_counter[i]--;
            if (timer_counter[i] == 0) {
                timer_flag[i] = 1;
            }
        }
    }
}
