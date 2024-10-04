// Manages all tasks in the application

#pragma once

#include "BaseTask.h"

namespace App
{
  class ApplicationTasks
  {
  public:
    static ApplicationTasks& GetInstance();

    // Initializes all application tasks
    bool InitTasks();

    ~ApplicationTasks() { }

  private:
    static const uint8_t NUM_APP_TASKS = 1;

    bool initialized;

    BaseTask* app_tasks[NUM_APP_TASKS];

    // Private as this class is a singleton
    explicit ApplicationTasks();

    // Class is not copyable, delete copy constructor and assignment operator
    ApplicationTasks(const ApplicationTasks&);
    ApplicationTasks& operator=(const ApplicationTasks);
  };
}
