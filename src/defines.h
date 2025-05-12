#ifndef DEFINES_H
#define DEFINES_H


// Pin Mappings
#define COOLER_LED1 8
#define COOLER_LED2 9

#define HEATER_LED1 6
#define HEATER_LED2 7

#define HUMIDIFIER_LED1 10
#define HUMIDIFIER_LED2 17


// Thresholds
#define COOLER_THRESHOLD 20.0 // Celsius, above this start cooling
#define HEATER_WARNING_THRESHOLD 30.0 // Celsius, below this start heater warning
#define HEATER_DANGER_THRESHOLD 1.0 // Celsius, below this heater danger
#define HUMIDIFIER_THRESHOLD 100.0 // % humidity, below this start humidifier

// Timer Definitions
#define TIMER_HUMIDIFIER_GREEN 0
#define TIMER_HUMIDIFIER_YELLOW 1
#define TIMER_HUMIDIFIER_RED 2

#endif
