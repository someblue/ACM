#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 310
#define NAMELEN 55
#define NUMPB 15

using namespace std;

struct struct_team{
    char name[NAMELEN];
    bool ac[NUMPB];
    int time[NUMPB],att[NUMPB],acnum,tottime;
    struct_team()
    {
        memset(ac,0,sizeof(ac));
        memset(time,0,sizeof(ac));
        memset(att,0,sizeof(att));
        acnum=tottime=0;
    }
    void calcu_tottime(const int &m)
    {
        int i;
        for(i=0;i<m;i++)
            if(ac[i])
                tottime+=(att[i]-1)*20+time[i];
    }
    friend bool operator < (struct_team a,struct_team b)
    {
        return (a.acnum>b.acnum)||(a.acnum==b.acnum&&a.tottime<b.tottime)
            ||(a.acnum==b.acnum&&a.tottime==b.tottime&&((strcmp(a.name,b.name))<0));
    }
};

struct_team team[N];

void print(const int &n,const int &m)
{
    int i,j;
    for(i=0;i<n;i++)
        team[i].calcu_tottime(m);
    sort(team,team+n);
    printf("rank name prosolved totaltime");
    for(i=0;i<m;i++)
        printf(" %c",i+'A');
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d %s %d %d",i+1,team[i].name,team[i].acnum,team[i].tottime);
        for(j=0;j<m;j++)
        {
            printf(" %d/",team[i].att[j]);
            if(team[i].ac[j])
                printf("%d",team[i].time[j]);
            else
                printf("-");
        }
        printf("\n");
    }
}

int main()
{
    freopen("case.txt","r",stdin);
    int n,m,k,i,ki,time,teamindex;
    char com[10],name[NAMELEN],pbindex,res[10];
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
        scanf("%s",team[i].name);
    for(ki=0;ki<k;ki++)
    {
        scanf("%s",com);
        if(strcmp(com,"show")==0)
        {
            print(n,m);
            continue;
        }
        scanf("%s%d%*c%c%s",name,&time,&pbindex,res);
        pbindex-='A';
        for(i=0;i<n;i++)
            if(strcmp(team[i].name,name)==0)
                teamindex=i;
        if(team[teamindex].ac[pbindex]) continue;
        team[teamindex].att[pbindex]++;
        if(strcmp(res,"AC")==0)
        {
            team[teamindex].ac[pbindex]=1;
            team[teamindex].acnum++;
            team[teamindex].time[pbindex]=time;
        }
    }
    return 0;
}
