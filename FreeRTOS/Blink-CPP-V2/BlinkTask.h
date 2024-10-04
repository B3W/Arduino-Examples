// Implementation of FreeRTOS blink example in CPP

#pragma once

#include "BaseTask.h"

namespace App
{
  class BlinkTask : public BaseTask
  {
  public:
    static BlinkTask& GetInstance();

    virtual ~BlinkTask() { }

  protected:
    // Called once prior to main task logic running
    bool Init() override;

    // Called once per interval tick of the task
    bool Tick() override;

    // Called once on error and/or shutdown
    bool Deinit() override;

  private:
    static const uint16_t TASK_INTERVAL_MS = 1000;
    static const configSTACK_DEPTH_TYPE TASK_STACK_SIZE = 128;
    static const UBaseType_t TASK_PRIORITY = 2;

    // Keeps track of LED state
    bool led_on;

    // Private as this class is a singleton
    explicit BlinkTask();

    // Class is not copyable, copy contructor deleted
    BlinkTask(const BlinkTask&);

    // Class is not copyable, assignment operator deleted
    BlinkTask& operator=(const BlinkTask);
  };
}
