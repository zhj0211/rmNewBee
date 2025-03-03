#include <iostream>
#include "taskScheduler.h"

using namespace std;

TaskScheduler::TaskScheduler(){
}

TaskScheduler::~TaskScheduler() {
}

void TaskScheduler::add_robot(const string &name) {
    if(!RobotScheduler.count(name)){
        RobotScheduler[name] = new Robot(name);
    }
}

void TaskScheduler::delete_robot(const string &name) {
    map<string, Robot*>::iterator    it;
    if(RobotScheduler.count(name)){
        it  = RobotScheduler.find(name);
        RobotScheduler.erase(it);
    }
}

Robot* TaskScheduler::search_robot(const string &name) {
    if(RobotScheduler.find(name)!=RobotScheduler.end()) {
        return (RobotScheduler.find(name)->second);
    }

    return nullptr;
}

vector<string> TaskScheduler::robot_name() {
    vector<string>  robot_name;
    map<string, Robot*>::iterator    it;

    for(it=RobotScheduler.begin();it!=RobotScheduler.end();++it){
        robot_name.push_back(it->first);
    }

    return robot_name;
}