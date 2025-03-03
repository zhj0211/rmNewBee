#include <iostream>
#include "robot.h"

Robot::Robot(const std::string &robot_name) : name(robot_name){
}

Robot::~Robot() {
    int     i;
    int     id;
    std::string description;
    std::string task_status;
    std::set<Task>::iterator  it;

    for(it=task.begin();it!=task.end();it++) {
        
        task_status = it->get_task_status();
        
        if(task_status.compare("未执行")==0) {
            // 输出任务信息
            id          = it->get_task_id();
            description = it->get_task_description();
            std::cout<<"未完成任务ID："<<id<<", 描述："<<description<<std::endl;
        }
    }
}

int Robot::add_Task(int &i, const std::string &task_description, int &Task_Priority) {
    Task task1;
    task1.set_Task_ID(i);
    task1.set_description(task_description);
    task1.set_priority(Task_Priority);
    task.insert(task1);
    return 0;
}

void Robot::run_Task() {
    int     temp_priority;
    std::set<Task>::iterator    temp;
    std::set<Task>::iterator    it;
    for(it=task.begin();it!=task.end();it++) {
        if(it->get_task_priority()>temp_priority){
            temp_priority   = it->get_task_priority();
            temp    = it;
        }
    }
    const_cast<Task&>(*temp).update_Task();
}

int Robot::show_Task() {
    int     i;
    int     id;
    int     task_priority;
    std::string description;
    std::string task_status;
    std::set<Task>::iterator    it;

    if(task.size()==0) {
        return -1;
    }

    for(it=task.begin();it!=task.end();it++) {
        id              = it->get_task_id();
        task_status     = it->get_task_status();
        description     = it->get_task_description();
        task_priority   = it->get_task_priority();
        // 输出任务信息
        std::cout<<"未完成任务ID："<<id<<", 描述："<<description<<"，优先级："<<task_priority<<", 状态："<<task_status<<std::endl;
    }

    return 0;
}

void Robot::delete_Task() {
    int     temp_priority;
    std::set<Task>::iterator    temp;
    std::set<Task>::iterator    it;

    for(it=task.begin();it!=task.end();it++) {
        if(it->get_task_priority()<temp_priority){
            temp_priority   = it->get_task_priority();
            temp    = it;
        }
    }
    task.erase(temp);
}