#include <iostream>
#include <cstdio>
#define N 1010
#define TIMES 3

using namespace std;

int main()
{
    int p,index,maxnum,maxi;
    int i,j,k;
    int num[15];
    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        scanf("%d",&index);
        for(j=0;j<10;j++)
            scanf("%d",&num[j]);
        maxi=11;
        for(k=0;k<TIMES;k++)
        {
            num[maxi]=-2;
            maxnum=-1;
            for(j=0;j<10;j++)
            {
                if(maxnum<num[j])
                {
                    maxnum=num[j];
                    maxi=j;
                }
            }
        }
        printf("%d %d\n",index,maxnum);
    }
    return 0;
}
