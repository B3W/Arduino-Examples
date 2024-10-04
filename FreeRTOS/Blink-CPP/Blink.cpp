// Implementation of FreeRTOS blink example in CPP

#include <Arduino.h>
#include "Blink.h"
#include "Utils.h"

namespace
{
  const uint8_t LED_PIN = 2;
  const uint16_t LED_BLINK_DELAY = 250;

  // Keeps track of LED state
  bool ledOn = false;
}

namespace Blink
{
  BaseType_t TaskInit(void)
  {
    BaseType_t ret_code = pdPASS;

    ret_code = xTaskCreate(TaskBlink,    // Function that implements the task
                           "BlinkTask",  // Human readable name
                           128,          // This stack size can be checked and adjusted by reading the Stack Highwater
                           NULL,         // pvParameters - passed as parameter to task function (can be NULL)
                           2,            // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
                           NULL);        // Handle to created task (can be null)
    
    return ret_code;
  }

  
  void TaskBlink(void* pvParams)
  {
    UNUSED(pvParams);

    // Setup any HW necessary for this task
    pinMode(LED_PIN, OUTPUT);

    // Run mainloop (never exits)
    for (;;)
    {
      if (ledOn)
      {
        ledOn = false;
        digitalWrite(LED_PIN, LOW);  // Turn LED off
      }
      else
      {
        ledOn = true;
        digitalWrite(LED_PIN, HIGH); // Turn LED off
      }

      delay(LED_BLINK_DELAY);
    }
  }
}
