#include<iostream>
using namespace std;
int main(){
    int x=0,y=0,e=0,count=1;
    char q;
    for(int i=0;;i++){
    cin>>q;
    if(q=='a') count-=1;
    if(q=='d') count+=1;//count=1上 count=2右 count=3下 count=4左
    for(int i=0;count>=5;i++){
            count=count-4;
        }
        for(int i=0;count<=0;i++){
            count=count+4;
        }//让count保持在1234
    if(q=='w'){
        cin>>e;
        if(count==1) y+=e;
        if(count==2) x+=e;
        if(count==3) y-=e;
        if(count==4) x-=e;
    }
    if(q=='s'){
        cin>>e;
        if(count==1) y-=e;
        if(count==2) x-=e;
        if(count==3) y+=e;
        if(count==4) x+=e;
    }
    if(q=='a'||q=='d'||q=='w'||q=='s'){
    cout<<"位置： （"<<x<<", "<<y<<"), ";
        if(count==1) cout<<"方向： 上";
        if(count==2) cout<<"方向： 右";
        if(count==3) cout<<"方向： 下";
        if(count==4) cout<<"方向： 左";
    }
    }
    }
