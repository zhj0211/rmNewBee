#include <iostream>
#include "robot.h"

Robot::Robot(std::string robot_name) : name(robot_name), Task_number(0){
}

Robot::~Robot() {
    int     i;
    int     id;
    std::string description;
    std::string task_status;

    for(i=0;i<Task_number;i++) {
        
        task_status = task[i].get_task_status();
        
        if(task_status.compare("未执行")==0) {
            // 输出任务信息
            id          = task[i].get_task_id();
            description = task[i].get_task_description();
            std::cout<<"未完成任务ID："<<id<<", 描述："<<description<<std::endl;
        }
    }
}

int Robot::add_Task(int i, std::string task_description) {
    if(i==(++Task_number)){
        task[i-1].set_Task_ID(i);
        task[i-1].set_description(task_description);
        return 0;
    }
    else{
        return -1;
    }
}

void Robot::run_Task() {
    int i;
    for(i=0;i<Task_number;i++){
        task[i].update_Task();
    }
}

void Robot::show_Task() {
    int     i;
    int     id;
    std::string description;
    std::string task_status;
    for(i=0;i<Task_number;i++) {
        id          = task[i].get_task_id();
        task_status = task[i].get_task_status();
        description = task[i].get_task_description();
        // 输出任务信息
        std::cout<<"未完成任务ID："<<id<<", 描述："<<description<<", 状态："<<task_status<<std::endl;
    }
}