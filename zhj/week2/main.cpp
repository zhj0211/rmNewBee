#include <iostream>
#include "task.h"
#include "robot.h"

using namespace std;

int main()
{
    int     id;
    string  command;
    string  description;
    string  robot_name;

    // 构造机器人实例
    cin>>robot_name;
    Robot   robot(robot_name);

    while(1){
        cin>>command;
        if(command=="添加") {
            cin>>id;
            cin>>description;
            robot.add_Task(id, description);
        }else if(command=="执行") {
            robot.run_Task();
        }else if(command=="显示") {
            robot.show_Task();
        }else if(command=="退出") {
            break;
        }else {
            cout<<"error"<<endl;
        }
    }
    return 0;
}