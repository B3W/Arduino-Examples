// Implements base task that all other tasks with derive from

#pragma once

#include <Arduino_FreeRTOS.h>

namespace App
{
  class BaseTask
  {
  public:
    static const uint8_t MAX_TASK_NAME_LENGTH = 32;

    BaseTask(const char* name,
             const uint16_t interval_ms,
             const configSTACK_DEPTH_TYPE stack_size,
             const UBaseType_t priority);

    virtual ~BaseTask();

    // Creates task. Task will be running upon successful completion of this method
    bool Create();

    // Call to shutdown task
    void Shutdown();

    // Retrieves name of the task
    void GetName(char name[MAX_TASK_NAME_LENGTH]);

  protected:
    // Called once prior to main task logic running
    virtual bool Init() = 0;

    // Called once per interval tick of the task
    virtual bool Tick() = 0;

    // Called once on error and/or shutdown
    virtual bool Deinit() = 0;

  private:
    // Human readable name for task
    char task_name[MAX_TASK_NAME_LENGTH];

    // Interval, in milliseconds, for task's Tick event to run
    const uint16_t task_interval;

    // Size, in words, for task's stack
    const configSTACK_DEPTH_TYPE task_stack_size;

    // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest
    const UBaseType_t task_priority;

    // Handle to created task
    TaskHandle_t task_handle;

    // Flag indicating if task is running
    bool is_running;

    // Runs task's logic
    static void Mainloop(void* task_ptr);
  };
}
