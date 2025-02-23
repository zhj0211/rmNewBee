#pragma once

#include <string>
#include "task.h"

#define MAX_TASK    100

class Robot
{
private:
    int     Task_number;
    std::string  name;
    Task    task[MAX_TASK];
public:
    Robot(std::string robot_name);
    ~Robot();

    int add_Task(int i, std::string task_description);
    void run_Task();
    void show_Task();
};