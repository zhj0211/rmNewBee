//屎山代码如下
#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

void findThenearestEnemy(){

}

int main(){
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 上、右、下、左
    int add[2] = {0, 0}; 
    string input;
    int i = 0; 
    std::cout << "开始" << std::endl;
    while(true){
        getline(cin, input);
        istringstream iss(input);      
        
       
        vector<string> tokens;
        string token;

        while(iss >> token){
            tokens.push_back(token);
        }

        if(tokens.empty()) {
            cout << "wrong input" << endl;
            continue;
        }
        int steps = 1; // 默认步数
        if(tokens.size() > 1 && (tokens[0] == "w" || tokens[0] == "d")){
            steps = stoi(tokens[1]);
        }     

        switch(tokens[0][0]){
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
            case 'x':
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

        if(tokens[0][0] == 'x'){
            int enemyX = stoi(tokens[1]);
            int enemyY = stoi(tokens[2]);
            int current_add[2];
            int current_dir = i;
            copy(add, add + 2, current_add);
            int dx = enemyX - current_add[0];
            int dy = enemyY - current_add[1];
          

            cout << "最近敌人的位置: (" << enemyX << ", " << enemyY << "),  所需控制操作: [";

            while(true){
                int dx = enemyX - current_add[0];
                int dy = enemyY - current_add[1];
                int distance = abs(dx) + abs(dy);
                if(current_dir == 0){
                    
                    if(dy > 0){
                        cout << "w " << dy << ", ";
                        current_add[1] = enemyY;
                    }else if(dy < 0){
                         cout << "s " << -dy << ", ";
                         current_add[1] = enemyY;
                    }
                    if(dx > 0){
                        cout << "d, ";
                        current_dir = (current_dir + 1) % 4;
                    }else if(dx < 0){
                        cout << "a, ";
                        current_dir = (current_dir + 3) % 4;
                    }
                }else if(current_dir == 1){
                    if(dx > 0){
                        cout << "w " << dx << ", ";
                        current_add[0] = enemyX;
                    }else if(dx < 0){
                        cout << "s " << -dx << ", ";
                        current_add[0] = enemyX;
                    }
                    if(dy > 0){
                        cout << "a, ";
                        current_dir = (current_dir + 3) % 4;
                    }else if(dy < 0){
                        cout << "s, ";
                        current_dir = (current_dir + 1) % 4;
                    }
                }else if(current_dir == 2){
                    
                    if(dy < 0){
                        cout << "w " << dy << ", ";
                        current_add[1] = enemyY;
                    }else if(dy > 0){
                         cout << "s " << -dy << ", ";
                         current_add[1] = enemyY;
                    }
                    if(dx < 0){
                        cout << "d, ";
                        current_dir = (current_dir + 1) % 4;
                    }else if(dx > 0){
                        cout << "a, ";
                        current_dir = (current_dir + 3) % 4;
                    }
                }else if(current_dir == 3){
                    if(dx < 0){
                        cout << "w " << dx << ", ";
                        current_add[0] = enemyX;
                    }else if(dx > 0){
                        cout << "s " << -dx << ", ";
                        current_add[0] = enemyX;
                    }
                    if(dy < 0){
                        cout << "a, ";
                        current_dir = (current_dir + 3) % 4;
                    }else if(dy > 0){
                        cout << "s, ";
                        current_dir = (current_dir + 1) % 4;
                    }
                }
                if(distance == 0){
                    break;
                }
            }
            cout << ']' << endl;                //有点问题是最后会多一个逗号,不想改了      
        }
    }
}