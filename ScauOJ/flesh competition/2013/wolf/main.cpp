#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1010

using namespace std;

int g[N][N],id[N],vote[N];

inline int votedead(int num[],int n)
{
    int i,maxn,maxi;
    memset(vote,0,sizeof(vote));
    for(i=1;i<=n;i++)
        if(num[i]>0)
            vote[num[i]]++;
    maxn=0;
    for(i=1;i<=n;i++)
        if(maxn<vote[i]){maxn=vote[i];maxi=i;}
    return maxi;
}

int main()
{
    int t,n,k,i,j,ans,key;
    char res[10];
    scanf("%d",&t);
    while(t--)
    {
        memset(id,0,sizeof(id));//id[i]=0 for wolf, 1 for human
        scanf("%d%d",&n,&k);
        for(i=0;i<k;i++)
        {
            for(j=0;j<=n;j++)
                scanf("%d",&g[i][j]);
            id[g[i][0]]=1;
        }
        scanf("%s",res);
        //-----find key-----
        if(strcmp(res,"hehe")==0)
        {
            key=votedead(g[k-1],n);
            for(i=1;i<=n;i++)if(g[k-1][i]!=-1&&i!=key){id[i]=1;}
        }
        else if(g[k-1][1]==0)
        {
            if(k==1)
            {
                ans=n-1;
                goto fly;
            }
            vote[g[k-1][0]]=1;
            int lastdead=votedead(g[k-2],n);
            for(i=1;i<=n;i++)if(g[k-2][i]!=-1&&i!=g[k-1][0]&&i!=lastdead){key=i;break;}
        }
        else
        {
            int human=votedead(g[k-1],n);
            id[human]=1;
            for(i=1;i<=n;i++)if(g[k-1][i]==human){key=i;break;}
        }
//        printf("key=%d\n",key);
        //-----end find key-----
        for(i=0;i<k;i++)
        {
            id[g[i][key]]=1;
            for(j=1;j<=n;j++)
                if(!id[j] && g[i][j]!=-1 && g[i][j]!=g[i][key]) id[j]=1;
        }
        ans=0;
        for(i=1;i<=n;i++) ans+= !id[i];
        fly:
        printf("%d\n",ans);
    }
    return 0;
}

/*    bug:
data:
1
10 2
2 3 -1 5 3 3 7 6 6 6 10
6 7 -1 -1 7 7 1 1 1 1 1
hehe

ans 1

当hehe时候，只判定了狼人是谁,没有确定其他人必是村民*/
