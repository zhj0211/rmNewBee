#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 上、右、下、左
    int add[2] = {0, 0}; 
    string input;
    int i = 0; 
    std::cout << "开始" << std::endl;
    while(1){
        getline(cin, input);
        istringstream iss(input);      
        char ch;
        int steps = 1; // 默认步数
        iss >> ch; // 方向
        iss >> steps; // 步数

        switch(ch){
            case 'w':
                add[0] += dir[i][0] * steps;
                add[1] += dir[i][1] * steps;
                break;
            case 's':
                add[0] -= dir[i][0] * steps;
                add[1] -= dir[i][1] * steps;
                break;
            case 'a':
                i = (i + 3) % 4; // 左转
                break;
            case 'd':
                i = (i + 1) % 4; // 右转
                break;
            case 'q': 
                cout << "退出程序" << endl;
                return 0;
            default:
                cout << "wrong input" << endl;
        }

        string direction;
        if(i == 0){
            direction = "上";
        }else if(i == 1){
            direction = "右";
        }else if(i == 2){
            direction = "下";
        }else{
            direction = "左";
        }

        cout << "位置: (" << add[0] << ", " << add[1] << "), 方向: " << direction << endl;
    }
}