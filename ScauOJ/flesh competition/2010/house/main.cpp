#include <iostream>

using namespace std;

int main()
{
    int x,y,z,cnt=0;
    cin>>x>>y>>z;
    while(!(x==0&&y==0&&z==0))
    {
        if(x>=2&&z>=1){x-=2;z--;cnt++;}
        else if(x>=2&&y>=1){x-=2;y--;cnt++;}
        else if(z>=2){z-=2;cnt++;}
        else if(x>=3){x-=3;cnt++;}
        else if(y>=1&&z>=1){y--;z--;cnt++;}
        else if(y>=2){y-=2;cnt++;}
        else if(x>=1&&z>=1){x--;z--;cnt++;}
        else if(x>=1&&y>=1){x--;y--;cnt++;}
        else if(z>=1){z--;cnt++;}
        else if(y>=1){y--;cnt++;}
        else if(x>=1){x--;cnt++;}
        //cout<<x<<' '<<y<<' '<<z<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}
