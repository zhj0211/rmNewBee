#pragma once

#include <string>

class Task
{
private:
    int     Task_ID;
    int     Task_Priority;
    std::string  status;
    std::string  description;
public:
    Task();

    // 更新任务状态
    void update_Task();

    // 获取任务信息
    int get_task_id() const;
    int get_task_priority() const;
    std::string get_task_status() const;
    std::string get_task_description() const;

    // 更改任务信息
    void set_Task_ID(const int &task_ID);
    void set_description(const std::string &task_description);
    void set_priority(const int &task_priority);

    // 重载小于号
    bool operator<(const Task& other) const;
};