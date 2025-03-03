#pragma once

#include <string>
#include <vector>
#include <map>
#include "task.h"
#include "robot.h"

using namespace std;

class TaskScheduler
{
private:
    map<string, Robot*> RobotScheduler;
public:
    TaskScheduler();
    ~TaskScheduler();
    
    void    add_robot(const string &name);
    void    delete_robot(const string &name);
    Robot*  search_robot(const std::string &name);
    vector<string>    robot_name();
};