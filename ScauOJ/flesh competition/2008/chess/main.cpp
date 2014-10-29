#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int s,dx,dy,x,y,nx,ny,max;
    int k;
    while(cin>>s>>x>>y>>dx>>dy)
    {
        if(s==0&&x==0&&y==0&&dx==0&&dy==0) break;
        max=6*s;
        nx=x;ny=y;
        for(k=0;nx<max&&ny<max&&nx>=0&&ny>=0;k++)
        {
            nx=k*dx+x;
            ny=k*dy+y;
            if((nx%s!=0&&ny%s!=0)&&((nx/s+ny/s)%2))
            {
                break;
            }
            if(dx==0&&dy==0)
            {
                nx=ny=max;
                break;
            }
        }
        if(nx>=max||ny>=max||nx<0||ny<0)
            printf("The flea cannot escape from black squares.\n");
        else
            printf("After %d jumps the flea lands at (%d, %d).\n",k,nx,ny);
    }
    return 0;
}
