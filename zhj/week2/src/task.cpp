#include "task.h"

Task::Task() {
    Task_ID     =0;
    description ="";
    status      ="未执行";
}

void Task::update_Task() {
    status  ="已执行";
}

int Task::get_task_id() {
    return Task_ID;
}

std::string Task::get_task_status() {
    return status;
}

std::string Task::get_task_description() {
    return description;
}

void Task::set_Task_ID(int task_ID) {
    Task_ID = task_ID;
}

void Task::set_description(std::string task_description) {
    description = task_description;
}