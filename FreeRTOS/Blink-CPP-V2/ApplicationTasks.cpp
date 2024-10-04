// Manages all tasks in application

#include "ApplicationTasks.h"
#include "BlinkTask.h"

namespace App
{
  ApplicationTasks& ApplicationTasks::GetInstance()
  {
    static ApplicationTasks tasks;
    return tasks;
  }
  
  bool ApplicationTasks::InitTasks()
  {
    bool success = true;

    for (uint8_t i = 0; success && (i < NUM_APP_TASKS); i++)
    {
      success = app_tasks[i]->Create();
    }

    return success;
  }

  ApplicationTasks::ApplicationTasks()
    : initialized(false),
      app_tasks{ &BlinkTask::GetInstance() }
  {
  }
}
