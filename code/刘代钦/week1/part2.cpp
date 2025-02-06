#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

struct enemy{
    int enemy_x;
    int enemy_y;
};

int main(){
    int x=0,y=0;
    int direction=0;
    char input_dir;
    int position;
    vector<enemy>Em;
    enemy index;
    while (1)
    {
       cin>>input_dir;
        if(input_dir=='w') {
            cin>>position;
            if (direction==0)
            {
                y+=position;
            }
            else if(direction==90)
            {
                x+=position;
            }
            else if(direction==180)
            {
                y-=position;
            }
            else if(direction==270)
            {
                x-=position;
            }
        }
        else if(input_dir=='s'){
            cin>>position;
            if (direction==0)
            {
                y-=position;
            }
            else if(direction==90)
            {
                x-=position;
            }
            else if(direction==180)
            {
                y+=position;
            }
            else if(direction==270)
            {
                x+=position;
            }
        }  
        else if(input_dir=='a'){
            direction=direction+360-90;
            while(direction>=360)
            {
                direction-=360;
            }
        }    
        else if(input_dir=='d'){
            direction+=90;
            while(direction>=360)
            {
                direction-=360;
            }
        }
        else if(input_dir=='x'){
            cin>>index.enemy_x>>index.enemy_y;
            enemy shortest_dis;
            int index_dis1,index_dis2;
            Em.push_back(index);
            index.enemy_x=0,index.enemy_y=0;
            index_dis1=abs(x-Em[0].enemy_x)+abs(y-Em[0].enemy_y);
            // cout<<"("<<enemy_index.enemy_x<<","<<enemy_index.enemy_y<<")"<<endl;
            if (Em.size()==1)
            {//`最近敌人位置: (x, y), 所需控制操作: [操作1，操作2，... ]`
                shortest_dis=Em[0];
            }
            else if (Em.size()>1){
                for (int i=0; i < Em.size(); i++)
                {
                        // index_dis2=abs(x-Em[i].enemy_x)+abs(y-Em[i].enemy_y);
                        index_dis2=sqrt(pow(x-Em[i].enemy_x,2)+pow(y-Em[i].enemy_y,2));
                        if (index_dis2<index_dis1)
                        {
                            shortest_dis=Em[i];
                        }
                           
                }
            }
            cout<<"最近敌人位置: ("<<shortest_dis.enemy_x<<","<<shortest_dis.enemy_y<<"), 所需控制操作: [";
            int step;
            int right;
            if (direction==0)
            {
                step=shortest_dis.enemy_y-y;
                right=shortest_dis.enemy_x-x;
            }
            else if (direction==90)
            {
                step=shortest_dis.enemy_x-x;
                right=y-shortest_dis.enemy_y;
            }
            else if (direction==180)
            {
                step=y-shortest_dis.enemy_y;
                right=x-shortest_dis.enemy_x;
            }
            else if (direction==270)
            {
                step=x-shortest_dis.enemy_x;
                right=shortest_dis.enemy_y-y;
            }

            if (step==0)
            {
                if (right>0)
                {
                    cout<<"d,";
                }
                else if (right<0)
                {
                    cout<<"a,";
                }
            }
            else if (step>0)
            {
                if (right>0)
                {
                    cout<<"w,"<<step;
                    cout<<"d,";
                }
                else if (right<0)
                {
                    cout<<"w,"<<step;
                    cout<<"a,";
                }
            }
            else{
               if (right>0)
                {
                    cout<<"s,"<<-step;
                    cout<<",d";
                }
                else if (right<0)
                {
                    cout<<"s,"<<-step;
                    cout<<",a";
                }
                else
                    cout<<"d,d";
            }
            cout<<"]"<<endl;
            continue;
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