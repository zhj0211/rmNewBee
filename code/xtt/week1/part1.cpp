#include<iostream>
#include<string>
using namespace std;
class robot
{
public:
	int position[2] = {0,0};
	string NowDirection="上";
	int DirectionNum = 1;
	void move(char direction,int distance)
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
			DirectionNum --; 
			if (DirectionNum < 1) { DirectionNum = 4; }
			direction();
			ShowInformation();
		}
		if (TurnDirection == 'd') 
		{
			DirectionNum ++; 
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
	void ShowInformation()
	{
		cout << "位置：(" <<position[0]<<","<<position[1]<<"), " << "方向：" << NowDirection << endl;
	}
 };
int main()
{
	robot xiaoli;
	char direction;
	int distance;
	while (1)
	{
		cin >> direction;
		if (direction == 'a' || direction == 'd')
		{
			xiaoli.turn(direction);
			continue;
		}
		cin >> distance;
		xiaoli.move(direction, distance);
	}
	return 0;
}