#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 60

using namespace std;

char type[N],letter[N];
int undo[N],sec[N];
bool sta[N];//0 for char, 1 for undo

void print(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d:",i);
        if(sta[i]) printf("\tundo %d\n",undo[i]);
        else printf("\ttype %c\n",type[i]);
        printf("\t%d\n",sec[i]);
    }
}

int main()
{
    int i,n,len,nowtime;
    char cmd[10],temp;
//    nowtime=1000000001;
//    printf("%d",nowtime);
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",cmd);
            if(cmd[0]=='t')
            {
                sta[i]=0;
                scanf("%c%c",&temp,&type[i]);
            }
            else
            {
                sta[i]=1;
                scanf("%d",&undo[i]);
            }
        }
        for(i=0;i<n;i++)
            scanf("%d",&sec[i]);
        //print(n);
        len=0;nowtime=1000000001;
        for(i=n-1;i>=0;i--)
        {
            if(sec[i]>=nowtime) continue;
            else nowtime=sec[i];
            if(sta[i])
            {
                nowtime-=undo[i];
            }
            else
            {
                letter[len++]=type[i];
            }
        }
        //print letter
        for(i=len-1;i>=0;i--)
            printf("%c",letter[i]);
        printf("\n");
    }
    return 0;
}
