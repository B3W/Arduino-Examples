// Implementation of FreeRTOS blink example in CPP

#include <Arduino.h>
#include "BlinkTask.h"

namespace
{
  const uint8_t LED_PIN = 2;
  const uint16_t LED_BLINK_DELAY = 250;
}

namespace App
{
  BlinkTask& BlinkTask::GetInstance()
  {
    static BlinkTask task;
    return task;
  }

  bool BlinkTask::Init()
  {
    // Setup any HW necessary for this task
    pinMode(LED_PIN, OUTPUT);

    return true;
  }

  bool BlinkTask::Tick()
  {
    if (led_on)
    {
      led_on = false;
      digitalWrite(LED_PIN, LOW);  // Turn LED off
    }
    else
    {
      led_on = true;
      digitalWrite(LED_PIN, HIGH); // Turn LED off
    }

    return true;
  }

  bool BlinkTask::Deinit()
  {
    // Do nothing
    return true;
  }

  BlinkTask::BlinkTask()
    : BaseTask("BlinkTask",
               TASK_INTERVAL_MS,
               TASK_STACK_SIZE,
               TASK_PRIORITY),
      led_on(false)
  {
  }
}
