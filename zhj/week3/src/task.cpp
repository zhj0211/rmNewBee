#include "task.h"

Task::Task() {
    Task_ID         = 0;
    Task_Priority   = 0;
    description     = "";
    status          = "未执行";
}

void Task::update_Task() {
    status  ="已执行";
}

int Task::get_task_id() const{
    return Task_ID;
}

int Task::get_task_priority() const{
    return Task_Priority;
}

std::string Task::get_task_status() const{
    return status;
}

std::string Task::get_task_description() const{
    return description;
}

void Task::set_Task_ID(const int &task_ID) {
    Task_ID = task_ID;
}

void Task::set_description(const std::string &task_description) {
    description = task_description;
}

void Task::set_priority(const int &task_priority) {
    Task_Priority   = task_priority;
}

bool Task::operator<(const Task& other) const {
    return this->get_task_priority() > other.get_task_priority(); // 优先级高的排在前面
}