#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <map>
#define VI vector<int>
#define N 1000010
using namespace std;
typedef long long ll;

int kb[12];
bool flag[2000],first;
VI ans;

bool cnt(int rn)
{
    int i,rnext,sta;
    for(i=0;i<10;i++)
    {
        if(first && !i ) {first=0;continue;}
        if((kb[i]%10+rn%10)%10==0||(kb[i]%10+rn%10)%10==1)
        {
            rnext=rn/10+kb[i]/10+(kb[i]%10+rn%10)/10;
            if(flag[rnext]) continue;
            flag[rnext]=1;
            ans.push_back((kb[i]%10+rn%10)%10);
            if(rnext==0||rnext==1)
            {
                if(rnext)
                    ans.push_back(rnext);
                return 1;
            }
            sta=cnt(rnext);
            if(sta) return 1;
            else ans.erase(ans.end()-1);
        }
    }
    return 0;
}

void run()
{
    int i,n;
    while(scanf("%d",&n),n!=0)
    {
        first=1;
        ans.clear();
        memset(flag,0,sizeof(flag));
        for(i=0;i<=9;i++) kb[i]=n*i;
        cnt(0);
//        if(cnt(0))
        {
            for(i=ans.size()-1;i>=0;i--)
                printf("%d",ans[i]);
            printf("\n");
        }
//        else
//            printf("ERROR\n");
    }
}

void text()
{
    int n,i;
    for(n=1;n<=200;n++)
    {
        first=1;
        ans.clear();
        memset(flag,0,sizeof(flag));
        for(i=0;i<=9;i++) kb[i]=n*i;
        //cnt(0);
        if(cnt(0))
        {
            printf("%d:",n);
            for(i=ans.size()-1;i>=0;i--)
                printf("%d",ans[i]);
            printf("\n\n");
        }
        else
            printf("ERROR\n");
    }
}

int main()
{
    //freopen("in","r",stdin);
//    run();
    text();
    return 0;
}
