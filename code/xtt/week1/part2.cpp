#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class robot
{
public:
	int position[2] = { 0,0 };
	string NowDirection = "上";
	int DirectionNum = 1;
	void move(char direction, int distance)
	{
		if (NowDirection == "上")
		{
			if (direction == 'w') { position[1] += distance; }
			else if (direction == 's') { position[1] -= distance; }
		}
		if (NowDirection == "右")
		{
			if (direction == 'w') { position[0] += distance; }
			else if (direction == 's') { position[0] -= distance; }
		}
		if (NowDirection == "下")
		{
			if (direction == 'w') { position[1] -= distance; }
			else if (direction == 's') { position[1] += distance; }
		}
		if (NowDirection == "左")
		{
			if (direction == 'w') { position[0] -= distance; }
			else if (direction == 's') { position[0] += distance; }
		}
		ShowInformation();
	}
	void turn(char TurnDirection)
	{
		if (TurnDirection == 'a')
		{
			DirectionNum--;
			if (DirectionNum < 1) { DirectionNum = 4; }
			direction();
			ShowInformation();
		}
		if (TurnDirection == 'd')
		{
			DirectionNum++;
			if (DirectionNum > 4) { DirectionNum = 1; }
			direction();
			ShowInformation();
		}
	}
	void direction()
	{
		if (DirectionNum == 1) { NowDirection = "上"; }
		if (DirectionNum == 2) { NowDirection = "右"; }
		if (DirectionNum == 3) { NowDirection = "下"; }
		if (DirectionNum == 4) { NowDirection = "左"; }
	}
	void FindEnemy(int EnemyX,int EnemyY)
	{
		int MoveDistance;
		if (EnemyX > position[0] && EnemyY > position[1])
		{
			if (DirectionNum == 3)
			{
				MoveDistance = EnemyY - position[1];
				cout << "最近敌人位置:("<<EnemyX << "," <<EnemyY<<"), 所需控制操作：[" <<"s "<<MoveDistance<<",a" << "]" << endl;
			}
			if (DirectionNum == 1)
			{
				MoveDistance = EnemyY - position[1];
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "w " << MoveDistance << ",d" << "]" << endl;
			}
			if (DirectionNum == 2)
			{
				MoveDistance = EnemyX - position[0];
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "w " << MoveDistance << ",a" << "]" << endl;
			}
			if (DirectionNum == 4)
			{
				MoveDistance = EnemyX - position[0];
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "s " << MoveDistance << ",d" << "]" << endl;
			}
        }
		if (EnemyX < position[0] && EnemyY > position[1])
		{
			if (DirectionNum == 3)
			{
				MoveDistance = EnemyY - position[1];
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "s " << MoveDistance << ",d" << "]" << endl;
			}
			if (DirectionNum == 1)
			{
				MoveDistance = EnemyY - position[1];
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "w " << MoveDistance << ",a" << "]" << endl;
			}
			if (DirectionNum == 2)
			{
				MoveDistance =  position[0]-EnemyX ;
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "s " << MoveDistance << ",a" << "]" << endl;
			}
			if (DirectionNum == 4)
			{
				MoveDistance = position[0] - EnemyX;
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "w " << MoveDistance << ",d" << "]" << endl;
			}
		}
		if (EnemyX < position[0] && EnemyY < position[1])
		{
			if (DirectionNum == 3)
			{
				MoveDistance = position[1]-EnemyY  ;
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "w " << MoveDistance << ",d" << "]" << endl;
			}
			if (DirectionNum == 1)
			{
				MoveDistance = position[1] - EnemyY;
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "s " << MoveDistance << ",a" << "]" << endl;
			}
			if (DirectionNum == 2)
			{
				MoveDistance = position[0]-EnemyX ;
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "s " << MoveDistance << ",d" << "]" << endl;
			}
			if (DirectionNum == 4)
			{
				MoveDistance = position[0] - EnemyX;
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "w " << MoveDistance << ",a" << "]" << endl;
			}
		}
		if (EnemyX > position[0] && EnemyY < position[1])
		{
			if (DirectionNum == 3)
			{
				MoveDistance = position[1]-EnemyY  ;
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "w " << MoveDistance << ",a" << "]" << endl;
			}
			if (DirectionNum == 1)
			{
				MoveDistance = position[1]-EnemyY  ;
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "s " << MoveDistance << ",d" << "]" << endl;
			}
			if (DirectionNum == 2)
			{
				MoveDistance = EnemyX - position[0];
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "w " << MoveDistance << ",d" << "]" << endl;
			}
			if (DirectionNum == 4)
			{
				MoveDistance = EnemyX - position[0];
				cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "s " << MoveDistance << ",a" << "]" << endl;
			}
		}
		if (EnemyY == position[1])
		{
			if (EnemyX > position[0]) {
				if (DirectionNum == 3)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "a" << "]" << endl;
				}
				if (DirectionNum == 1)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "d" << "]" << endl;
				}
				if (DirectionNum == 2)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "]" << endl;
				}
				if (DirectionNum == 4)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "d,d" << "]" << endl;
				}
			}
			if (EnemyX < position[0]) {
				if (DirectionNum == 3)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "d" << "]" << endl;
				}
				if (DirectionNum == 1)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "a" << "]" << endl;
				}
				if (DirectionNum == 2)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "a,a" << "]" << endl;
				}
				if (DirectionNum == 4)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "]" << endl;
				}
			}
		}
		if (EnemyX == position[0])
		{
			if (EnemyY > position[1]) {
				if (DirectionNum == 3)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "a,a" << "]" << endl;
				}
				if (DirectionNum == 1)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "]" << endl;
				}
				if (DirectionNum == 2)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" <<"a" << "]" << endl;
				}
				if (DirectionNum == 4)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "d" << "]" << endl;
				}
			}
			if (EnemyY < position[1]) {
				if (DirectionNum == 3)
				{
					cout << "最近敌人位置:(" << EnemyX <<","<< EnemyY << "), 所需控制操作：[" << "]" << endl;
				}
				if (DirectionNum == 1)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "a,a" << "]" << endl;
				}
				if (DirectionNum == 2)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：[" << "d" << "]" << endl;
				}
				if (DirectionNum == 4)
				{
					cout << "最近敌人位置:(" << EnemyX << "," << EnemyY << "), 所需控制操作：["<<"a"<< "]" << endl;
				}
			}
		}
			
		
	}
	void ShowInformation()
	{
		cout << "位置：(" << position[0] << "," << position[1] << "), " << "方向：" << NowDirection << endl;
	}
};
int main()
{
	robot xiaoli;
	char direction;
	int distance;
	int EnemyX, EnemyY;
	char EnemyName;
	while (1)
	{
		cin >> direction;
		if (direction == 'a' || direction == 'd')
		{
			cin >> EnemyName >> EnemyX >> EnemyY;
			xiaoli.turn(direction);
			xiaoli.FindEnemy(EnemyX, EnemyY);
			continue;
		}
		cin >> distance;
		
		cin >> EnemyName >> EnemyX >> EnemyY;
		xiaoli.move(direction, distance);
		xiaoli.FindEnemy(EnemyX, EnemyY);
	}
	return 0;
}