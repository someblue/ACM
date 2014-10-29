#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 100100
#define A m[0][p1]+m[1][p2]

using namespace std;

int m[2][MAXN];

int main()
{
    int t,sum,cnt[2],sex,p1,p2,tot,T;
    scanf("%d",&T);
    while(T--)
    {
        cnt[0]=cnt[1]=0;
        scanf("%d%d",&t,&sum);
        while(t--)
        {
            scanf("%d",&sex);
            scanf("%d",&m[sex][cnt[sex]]);
            cnt[sex]++;
        }
        p1=0;p2=cnt[1]-1;
        tot=0;
        while(p1<cnt[0]&&p2>=0)
        {
            //int &a=m[0][p1]+m[1][p2];
            if(A==sum)
            {
                tot++;
                p1++;p2--;
            }
            else if(A>sum)
                p2--;
            else if(A<sum)
                p1++;
        }
        printf("%d\n",tot);
    }
    return 0;
}
