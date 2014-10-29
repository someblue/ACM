#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1010
using namespace std;
char s[5];
int cnt[5];
int rec[N];

int main()
{
    int n,m,i,j,t;
    bool fin;
    scanf("%d%d",&n,&m);
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        scanf("%s",s);
        t=s[0]-'0'+s[1]-'0';
        cnt[t]++;
    }
    fin=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j) printf(" ");
            if(fin) {printf("00");continue;}
            if(cnt[2])
            {
                printf("11");
                cnt[2]--;
                rec[j]=2;
            }
            else if(cnt[1]||cnt[3])
            {
                if(cnt[3]&&rec[j]==1)
                {
                    printf("01");
                    cnt[3]--;
                }
                else if()
            }
            else
            {
                printf("00");
                fin=1;
            }
        }
        printf("\n");
    }
    return 0;
}
