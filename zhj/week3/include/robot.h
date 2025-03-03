#pragma once

#include <string>
#include <set>
#include "task.h"

class Robot
{
private:
    std::string         name;
    std::set<Task>   task;
public:
    Robot(const std::string &name);
    ~Robot();

    int     add_Task(int &i, const std::string &task_description, int &Task_Priority);
    void    run_Task();
    int     show_Task();
    void    delete_Task();
};