// Implementation of FreeRTOS blink example in CPP

#pragma once

#include <Arduino_FreeRTOS.h>

namespace Blink
{
  // Function which initializes all Blink tasks
  BaseType_t TaskInit(void);

  // Function which implements blink FreeRtos Task logic
  void TaskBlink(void* pvParams);
}
