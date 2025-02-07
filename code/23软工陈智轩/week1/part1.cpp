#include <iostream>
#include <string>
using namespace std;

// 定义方向枚举
enum Direction { UP, RIGHT, DOWN, LEFT };

// 机器人类
class Robot {
private:
    int x, y;
    Direction dir;

public:
    // 构造函数，初始化位置和方向
    Robot() : x(0), y(0), dir(UP) {}

    // 前进操作
    void moveForward(int steps) {
        switch (dir) {
            case UP: y += steps; break;
            case RIGHT: x += steps; break;
            case DOWN: y -= steps; break;
            case LEFT: x -= steps; break;
        }
    }

    // 后退操作
    void moveBackward(int steps) {
        switch (dir) {
            case UP: y -= steps; break;
            case RIGHT: x -= steps; break;
            case DOWN: y += steps; break;
            case LEFT: x += steps; break;
        }
    }

    // 顺时针旋转
    void turnshun() {
        dir = (Direction)((dir + 1) % 4);
    }

    // 逆时针旋转
    void turnni() {
        dir = (Direction)((dir - 1 + 4) % 4);
    }

    // 获取当前方向名称
    string getDirection() const {
        switch (dir) {
            case UP: return "上";
            case RIGHT: return "右";
            case DOWN: return "下";
            case LEFT: return "左";
        }
        return "";
    }

    // 输出当前位置和方向
    void print() const {
        cout << "位置: (" << x << ", " << y << "), 方向: " << getDirection() << endl;
    }
};

int main() {
    Robot robot;
    string command;

    while (true) {
        cout << "请输入指令 (w 数字1, s 数字1, a, d): ";
        cin>>command;

        if (command.empty()) break;

        char action = command[0];
        int steps = 0;

        if (action == 'w' || action == 's') {
            steps = command[2];
        }

        switch (action) {
            case 'w':
                robot.moveForward(steps);
                break;
            case 's':
                robot.moveBackward(steps);
                break;
            case 'a':
                robot.turnshun();
                break;
            case 'd':
                robot.turnni();
                break;
            default:
                cout << "无效指令" << endl;
                continue;
        }

        robot.print();
    }

    return 0;
}