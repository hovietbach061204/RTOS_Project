#ifndef SOFTWARE_TIMER_H
#define SOFTWARE_TIMER_H

// #ifdef __cplusplus
// extern "C" {
// #endif

void Timer_Set(int index, int value);
int Timer_IsExpired(int index);
void Timer_Run(void);

// #ifdef __cplusplus
// }
// #endif

#endif
