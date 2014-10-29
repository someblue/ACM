#include <iostream>
#include <cstdio>
#define max(x,y) ((x)>(y)?x:y)
#define MAXPOWER 2000
#define MAXN 50
#define INIHAPPY 1

using namespace std;

struct acm{
    int happy,power;
};

int main()
{
    freopen("case.txt","r",stdin);

    acm lian[MAXN+2];
    int i,j,n,pp=MAXPOWER,happy[MAXN+1][MAXPOWER+1];
    cin>>n;
    for(i=1;i<=n;i++) cin>>lian[i].happy;
    for(i=1;i<=n;i++) cin>>lian[i].power;
//dp-----------
    //initialize buttom---
    for(j=1;j<=pp;j++)
        happy[n+1][j]=1;
    //initialize buttom---
    for(i=n;i>=2;i--)
        for(j=1;j<=pp;j++)
        {
            happy[i][j]=happy[i+1][j];
            if(j>lian[i].power)
                happy[i][j]=max(happy[i][j], happy[i+1][j-lian[i].power] + lian[i].happy);
        }
    //caculate result
    happy[1][MAXPOWER]=happy[2][MAXPOWER];
    if(MAXPOWER>lian[1].power)
        happy[1][MAXPOWER]=max(happy[1][MAXPOWER],happy[2][MAXPOWER-lian[1].power] + lian[1].happy);
//dp------------
    cout<<happy[1][2000]<<endl;
    return 0;
}
