#include <iostream>
using namespace std;

int main(){
    int x=0,y=0;
    int direction=0;
    char input_dir;
    int step;
    while (1)
    {
       cin>>input_dir;
        switch (input_dir)
        {
        case 'w':
            cin>>step;
            if (direction==0)
            {
                y+=step;
            }
            else if(direction==90)
            {
                x+=step;
            }
            else if(direction==180)
            {
                y-=step;
            }
            else if(direction==270)
            {
                x-=step;
            }
            break;
        case 's':
            cin>>step;
            if (direction==0)
            {
                y-=step;
            }
            else if(direction==90)
            {
                x-=step;
            }
            else if(direction==180)
            {
                y+=step;
            }
            else if(direction==270)
            {
                x+=step;
            }
            break;
         case 'a':
            direction=direction+360-90;
            while(direction>=360)
            {
                direction-=360;
            }
            break;
         case 'd':
            direction+=90;
            while(direction>=360)
            {
                direction-=360;
            }
            break;
        }
        cout<<"位置:("<<x<<","<<y<<"),方向:";
        switch (direction)//位置: (x, y), 方向: 方向名称
        {
        case 0:
           cout<<"上"<<std::endl;
            break;
        case 90:
            cout<<"右"<<std::endl;
            break;
        case 180:
            cout<<"下"<<std::endl;
            break;
        case 270:
            cout<<"左"<<std::endl;
            break;
        }
    }
    return 0;
}