// Implements base task that all other tasks with derive from

#include <Arduino.h>
#include "BaseTask.h"

namespace App
{
  BaseTask::BaseTask(const char* name,
                     const uint16_t interval_ms,
                     const configSTACK_DEPTH_TYPE stack_size,
                     const UBaseType_t priority)
    : task_name(),
      task_interval(interval_ms),
      task_stack_size(stack_size),
      task_priority(priority),
      is_running(false)
  {
    if (name != NULL)
    {
      strncpy(task_name, name, MAX_TASK_NAME_LENGTH);
      task_name[MAX_TASK_NAME_LENGTH - 1] = '\0';  // Ensure null termination
    }
  }
  
  BaseTask::~BaseTask()
  {
  }

  bool BaseTask::Create()
  {
    BaseType_t ret_code = pdPASS;

    is_running = true;
    ret_code = xTaskCreate(Mainloop,          // Function that implements the task
                           task_name,         // Human readable name
                           task_stack_size,   // This stack size can be checked and adjusted by reading the Stack Highwater
                           this,              // pvParameters - passed as parameter to task function (can be NULL)
                           task_priority,     // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
                           &task_handle);     // Handle to created task (can be null)

    is_running = ret_code == pdPASS; // Correct after creation if needed
    return ret_code == pdPASS;
  }

  void BaseTask::Shutdown()
  {
    is_running = false;
  }

  void BaseTask::GetName(char name[MAX_TASK_NAME_LENGTH])
  {
    strncpy(name, task_name, MAX_TASK_NAME_LENGTH);
  }

  void BaseTask::Mainloop(void* task_ptr)
  {
    BaseTask* task = static_cast<BaseTask*>(task_ptr);
    bool success = task->Init();

    while (success && task->is_running)
    {
      delay(task->task_interval);
      success = task->Tick();
    }

    task->Deinit();

    if (!success)
    {
      // TODO Handle error
    }

    // Loop forever
    const uint16_t TASK_SHUTDOWN_DELAY = 2000;
    while (true)
    {
      delay(TASK_SHUTDOWN_DELAY);
    }
  }
}
