////////
//
//      week1/part2.cpp
//
////////

#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>

#define MAX_DISTANCE    10000000

using namespace std;

// 声明
void change_location(int direction, int &x, int &y, int distance);
void print_location(int direction, int x, int y, int distance);
int find_near(int x, int y, vector<int> &enemies_x, vector<int> &enemies_y);
int find_operation(int x, int y, int direction, vector<int> &enemies_x, vector<int> &enemies_y);

// 向前走
void change_location(int direction, int &x, int &y, int distance){

    if (direction == 0){
        y += distance;
    }else if (direction == 90){
        x += distance;
    }else if (direction == 180){
        y -= distance;
    }else if (direction == 270){
        x -= distance;
    }

}

void print_location(int direction, int x, int y, int distance){
    cout<<"位置：("<<x<<", "<<y<<"), 方向：";
    if (direction == 0){
        cout<<"上"<<endl;
    }else if (direction == 90){
        cout<<"右"<<endl;
    }else if (direction == 180){
        cout<<"下"<<endl;
    }else if (direction == 270){
        cout<<"左"<<endl;
    }

}

int find_near(int x, int y, vector<int> &enemies_x, vector<int> &enemies_y){
    int i;
    int temp;
    int flag;
    int distance;

    distance    = MAX_DISTANCE;

    for(i=0;i<size(enemies_x);i++){
        temp    = pow((x-enemies_x[i]), 2)+pow((y-enemies_y[i]), 2);
        if(temp<distance){
            //distance    = temp;       //存储距离
            flag        = i;
        }
    }

    return  flag;
}

int find_operation(int x, int y, int direction, vector<int> &enemies_x, vector<int> &enemies_y){
    int i;
    int temp;
    int index;
    int horizontal_distance;    // 横向距离 + -
    int vertical_distance;      // 纵向距离 + -

    // find index of the nearist enemy
    index   = find_near(x, y, enemies_x, enemies_y);

    horizontal_distance = enemies_x[index]-x;
    vertical_distance   = enemies_y[index]-y;

    for(i=1;i<=direction/90;i++){
        temp                = horizontal_distance;
        horizontal_distance = vertical_distance;
        vertical_distance   = temp;

        i%2==0 ? horizontal_distance *= -1 : vertical_distance *= -1;
    }

    cout<<horizontal_distance<<vertical_distance;

    cout<<"最近敌人位置: ("<<enemies_x[index]<<", "<<enemies_y[index]<<"), 所需控制操作: [";

    if(horizontal_distance>0){
        cout<<"d "<<fabs(horizontal_distance);

        if(vertical_distance>0){
            cout<<" , a";
        }else if(vertical_distance<0){
            cout<<" , d";
        }
    }else if(horizontal_distance<0){
        cout<<"a "<<fabs(horizontal_distance);

        if(vertical_distance>0){
            cout<<" , d";
        }else if(vertical_distance<0){
            cout<<" , a";
        }
    }else{
        if(vertical_distance<0){
            cout<<"s";
        }
    }
    cout<<"]"<<endl;

    return 1;
}

int main()
{
    int         x;
    int         y;
    int         flag;
    char        order;
    int         distance;
    int         direction;  // “上”（0°）、“右”（90°）、“下”（180°）、“左”（270°）
    int         enemy_count;
    int         enemy_x;
    int         enemy_y;
    vector<int> enemies_x;
    vector<int> enemies_y;

    // 初始位置
    x           = 0;
    y           = 0;
    direction   = 0;
    distance    = 0;
    enemy_count = 0;

    // w+数字1  数字1是一个正整数，机器人沿当前方向前进这么多单位。
    // s+数字1  数字1是一个正整数，机器人沿当前方向后退这么多单位。
    // a        机器人逆时针转90°
    // d        机器人顺时针转90°
    // q        退出
    while(1){
        cin>>order;

        flag    = 0;

        if(order=='w'){
            cin>>distance;
            change_location(direction, x, y, distance);

        }else if(order=='s'){
            cin>>distance;
            direction   += 180;
            change_location(direction, x, y, distance);
            direction   -= 180;

        }else if(order=='a'){
            direction   -= 90;

        }else if(order=='d'){
            direction   += 90;

        }else if(order=='q'){
            cout<<"over"<<endl;
            return 0;
        }else if(order=='x'){
            cin>>enemy_x>>enemy_y;
            enemies_x.push_back(enemy_x);
            enemies_y.push_back(enemy_y);
            flag    = find_operation(x, y, direction, enemies_x, enemies_y);
            enemy_count++;
        }else{
            cout<<"error"<<endl;
        }

        direction   = (direction + 360) % 360;
        
        if(flag==0){
            print_location(direction, x, y, distance);
        }
    }

    return 0;
}