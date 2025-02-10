////////
//
//      week1/part1.cpp
//
////////

#include <iostream>

using namespace std;

// 声明
void change_location(int direction, int &x, int &y, int distance);
void print_location(int direction, int x, int y, int distance);


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

int main()
{
    int     x;
    int     y;
    char    order;
    int     distance;
    int     direction;  // “上”（0°）、“右”（90°）、“下”（180°）、“左”（270°）

    // 初始位置
    x           = 0;
    y           = 0;
    direction   = 0;
    distance    = 0;

    // w+数字1  数字1是一个正整数，机器人沿当前方向前进这么多单位。
    // s+数字1  数字1是一个正整数，机器人沿当前方向后退这么多单位。
    // a        机器人逆时针转90°
    // d        机器人顺时针转90°
    // q        退出
    while(1){
        cin>>order;

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
        }else{
            cout<<"error"<<endl;
        }

        direction   = (direction + 360) % 360;
        
        print_location(direction, x, y, distance);
    }

    return 0;
}