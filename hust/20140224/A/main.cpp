#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n[4];

int solve(int skip)
{
    int buf[3],p;
    int i,a,b,c;
    for(i=0,p=0;i<4;i++)
        if(i!=skip)
            buf[p++]=n[i];
    a=buf[0];b=buf[1];c=buf[2];
    if(a+b==c) return 1;
    if(a+b>c&&c-b<a) return 0;
    return 2;
}

int main()
{
    int res,temp;//res:0=trangle,1=segement,2=impossible
    int i;
    char pres[3][15]={"TRIANGLE","SEGMENT","IMPOSSIBLE"};
    for(i=0;i<4;i++)
        scanf("%d",&n[i]);
    sort(n,n+4);
    res=2;
    for(i=0;i<4;i++)
    {
        temp=solve(i);
        if(temp!=2)
        {
            if(res==2) res=1;
            res&=temp;
        }
    }
    printf("%s\n",pres[res]);
    return 0;
}
