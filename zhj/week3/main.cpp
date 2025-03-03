#include <iostream>
#include "task.h"
#include "robot.h"
#include "taskScheduler.h"

using namespace std;

int main()
{
    int             i;
    int             id;
    int             Task_Priority;
    string          command;
    string          description;
    string          robot_name;
    Robot*          robot;
    TaskScheduler   robots;
    vector<string>  names;

    while(1){
        cin>>command;
        if(command=="添加机器人") {
            cin>>robot_name;
            robots.add_robot(robot_name);
        }else if(command=="添加任务") {
            cin>>robot_name;
            cin>>id;
            cin>>description;
            cin>>Task_Priority;
            if((robot=robots.search_robot(robot_name))==nullptr){
                cout<<"can't find robot"<<endl;
            }else{
                robot->add_Task(id, description,Task_Priority);
            }
        }else if(command=="撤销任务") {
            cin>>robot_name;
            if((robot=robots.search_robot(robot_name))==nullptr){
                cout<<"can't find robot"<<endl;
            }
            robot->delete_Task();
        }else if(command=="执行任务") {
            cin>>robot_name;
            if((robot=robots.search_robot(robot_name))==nullptr){
                cout<<"can't find robot"<<endl;
            }
            robot->run_Task();
        }else if(command=="删除机器人") {
            cin>>robot_name;
            robots.delete_robot(robot_name);
        }else if(command=="查询任务") {
            cin>>robot_name;
            if((robot=robots.search_robot(robot_name))==nullptr){
                cout<<"can't find robot"<<endl;
            }
            if(robot->show_Task()==-1) {
                cout<<"no tasks for this robot"<<endl;
            }
        }else if(command=="获取机器人名称列表") {
            names   = robots.robot_name();
            for(i=0;i<names.size();i++) {
                cout<<names[i]<<endl;
            }
        }else if(command=="退出") {
            break;
        }else {
            cout<<"error"<<endl;
        }
    }
    
    return 0;
}