#include <iostream>
#include <cstdio>
#include <cstring>
#define N 110
#define SN 60

using namespace std;

char sb[N][SN],sf[N][SN];

int main()
{
    freopen("case.txt","r",stdin);
    int topb,topf,T,Ti;
    char com[SN],url[SN];
    scanf("%d",&T);
    for(Ti=1;Ti<=T;Ti++)
    {
        topb=topf=0;
        strcpy(url,"http://www.lightoj.com/");
        printf("Case %d:\n",Ti);
        while(scanf("%s",com),strcmp(com,"QUIT")!=0)
        {
            if(strcmp(com,"BACK")==0)
            {
                if(!topb)
                {
                    printf("Ignored\n");
                    continue;
                }
                strcpy(sf[topf++],url);
                strcpy(url,sb[--topb]);
                printf("%s\n",url);
                continue;
            }
            if(strcmp(com,"FORWARD")==0)
            {
                if(!topf)
                {
                    printf("Ignored\n");
                    continue;
                }
                strcpy(sb[topb++],url);
                strcpy(url,sf[--topf]);
                printf("%s\n",url);
                continue;
            }
            strcpy(sb[topb++],url);
            scanf("%s",url);
            printf("%s\n",url);
            topf=0;
        }
    }
    return 0;
}
