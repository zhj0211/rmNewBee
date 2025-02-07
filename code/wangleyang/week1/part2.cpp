#include<iostream>
using namespace std;
int main(){
    int x=0,y=0,e=0,count=1,o=-1,a=0,b=0,jinx=0,jiny=0;
    char q;
    int ex[100],ey[100];//储存位置
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
        if(count==1) cout<<"方向： 上"<<endl;
        if(count==2) cout<<"方向： 右"<<endl;
        if(count==3) cout<<"方向： 下"<<endl;
        if(count==4) cout<<"方向： 左"<<endl;
    }
    if(q=='x'){
        o+=1;
        cin>>ex[o]>>ey[o];
        a=ex[o]-x;
        b=ey[o]-y;
        jinx=ex[0],jiny=ey[0];
        if((a*a+b*b)<((jinx-x)*(jinx-x)+(jiny-y)*(jiny-y))){
            jinx=ex[o];
            jiny=ey[o];
        }//计算最近的敌人
        cout  << "最近敌人位置: ("<<jinx<<", "<<jiny<< "), 所需控制操作：[";
        if(count==2) cout<<"a,";
        if(count==3) cout<<"a,a,";
        if(count==4) cout<<"d,";
        //让方向都向上
        if((jinx-x)!=0&&(jiny-y)!=0){
            if((jiny-y)>0) cout<<"w "<<(jiny-y)<<',';
            if((jiny-y)<0) cout<<"s "<<-(jiny-y)<<',';
            //与敌人位于同一行
            if((jinx-x)>0) cout<<"d]";
            if((jinx-x)<0) cout<<"a]";
        }
        if((jinx-x)==0){
            if((jiny-y)>0) cout<<" ]";
            if((jiny-y)<0) cout<<"a,a]";
        }
        if((jiny-y)==0){
            if((jinx-x)>0) cout<<"d]";
            if((jinx-x)<0) cout<<"a]";
        }
    }
    }
}