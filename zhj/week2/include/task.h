#pragma once

#include <string>

class Task
{
private:
    int     Task_ID;
    std::string  status;
    std::string  description;
public:
    Task();

    // 更新任务状态
    void update_Task();

    // 获取任务信息
    int get_task_id();
    std::string get_task_status();
    std::string get_task_description();

    // 更改任务信息
    void set_Task_ID(int task_ID);
    void set_description(std::string task_description);
};