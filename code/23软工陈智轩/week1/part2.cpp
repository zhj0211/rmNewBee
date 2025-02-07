#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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

    // 获取当前位置
    int getX() const { return x; }
    int getY() const { return y; }

    // 获取当前方向
    Direction getD() const { return dir; }
};

// 敌人类
class Enemy {
private:
    static vector<pair<int, int>> enemies;  // 存储所有敌人位置

public:
    // 添加敌人位置
    static void addEnemy(int x, int y) {
        enemies.push_back({x, y});
    }

    // 找到距离机器人最近的敌人
    static pair<int, int> findNearestEnemy(const Robot& robot) {
        pair<int, int> nearest = {0, 0};
        double minDistance = 1000000;

        for (const auto& enemy : enemies) {
            double distance = abs(robot.getX() - enemy.first) + abs(robot.getY() - enemy.second);
            if (distance < minDistance) {
                minDistance = distance;
                nearest = enemy;
            }
        }

        return nearest;
    }

    // 计算所需操作
    static vector<string> calculateOperations(const Robot& robot, const pair<int, int>& target) {
        vector<string> operations;

        int dx = target.first - robot.getX();
        int dy = target.second - robot.getY();

        if (dx == 0 && dy == 0) {
            // 已经在目标位置
            return operations;
        }

        // 计算目标方向
        Direction targetDir;
        if (abs(dx) > abs(dy)) {
            targetDir = (dx > 0) ? RIGHT : LEFT;
        } else {
            targetDir = (dy > 0) ? UP : DOWN;
        }

        // 计算当前方向与目标方向的差值
        int diff = (targetDir - robot.getD() + 4) % 4;

        // 添加转向操作
        if (diff == 1) {
            operations.push_back("d");
        } else if (diff == 2) {
            operations.push_back("d");
            operations.push_back("d");
        } else if (diff == 3) {
            operations.push_back("a");
        }

        // 添加移动操作
        int distance = abs(dx) + abs(dy);
        if (distance > 0) {
            operations.push_back("w " + to_string(distance));
        }

        return operations;
    }
};

// 静态成员初始化
vector<pair<int, int>> Enemy::enemies;

int main() {
    Robot robot;
    string command;

    while (true) {
        cout << "请输入指令 (w 数字1, s 数字1, a, d, x 数字1 数字2): ";
        getline(cin, command);

        if (command.empty()) break;

        char action = command[0];
        int steps = 0;
        int enemyX = 0, enemyY = 0;

        if (action == 'w' || action == 's') {
            steps = command[2];
        } else if (action == 'x') {
            size_t space1 = command.find(' ');
            size_t space2 = command.find(' ', space1 + 1);
            enemyX = stoi(command.substr(space1 + 1, space2 - space1 - 1));
            enemyY = stoi(command.substr(space2 + 1));
        }
        switch (action) {
            case 'w':
                robot.moveForward(steps);
                break;
            case 's':
                robot.moveBackward(steps);
                break;
            case 'a':
                robot.turnni();
                break;
            case 'd':
                robot.turnshun();
                break;
            case 'x':
                Enemy::addEnemy(enemyX, enemyY);
                pair<int, int> nearestEnemy = Enemy::findNearestEnemy(robot);
                vector<string> operations = Enemy::calculateOperations(robot, nearestEnemy);
                cout << "最近敌人位置: (" << nearestEnemy.first << ", " << nearestEnemy.second << "), 所需控制操作: [";
                for (size_t i = 0; i < operations.size(); ++i) {
                    cout << operations[i];
                    if (i < operations.size() - 1) cout << ", ";
                }
                cout << "]" << endl;
                break;
            default:
                cout << "无效指令" << endl;
                continue;
        }

        robot.print();
    }

    return 0;
}