#include <Arduino.h>
#include "scheduler.h"

#include "blinky_task.h"
#include "sensor_task.h"
#include "heater_task.h"
#include "cooler_task.h"
#include "humidifier_task.h"
#include "software_timer.h"

void TIMER_ISR(void *pvParameters)
{
  while (1)
  {
    SCH_Update();
    vTaskDelay(10);
  }
}


void setup() {
    Serial.begin(115200);

    // Hardware init
    Wire.begin(GPIO_NUM_11, GPIO_NUM_12);
    dht20.begin();

    // LED subsystems
    setup_cooler_leds();
    setup_heater_leds();
    setup_humidifier_leds();

    xTaskCreate(TIMER_ISR, "TIMER_ISR", 2048, NULL, 2, NULL);


    SCH_Init();

    // Now safe to print
    Serial.println("Serial is finally ready.");

    SCH_Add_Task(Timer_Run, 0, 1);
    SCH_Add_Task(sensor_task, 0, 500);
    SCH_Add_Task(blinky_task, 0, 100);
    SCH_Add_Task(heater_task, 0, 100);
    SCH_Add_Task(cooler_task, 0, 100);
    SCH_Add_Task(humidifier_task, 0, 100);
}



void loop()
{
    SCH_Dispatch_Tasks();
}
