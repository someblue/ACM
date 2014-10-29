#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int N = 210;

int sg[N],n;
bool vis[N],skip[N],skip2[N];
char s[N];
vector<int> ans;

void show()
{
    printf("%d",ans[0]+1);
    for(int i=1;i<ans.size();++i)
        printf(" %d",ans[i]+1);
    printf("\n");
}

void build()
{
    sg[0]=0;
    sg[1]=sg[2]=sg[3]=1;
    int i,j;
    for(i=4;i<N;++i)
    {
        memset(vis,0,sizeof(vis));
        for(j=3;i-j>=0;++j)
        {
            int t=sg[i-j];
            if(j>=6)    t^=sg[j-5];
            vis[t]=1;
        }
        for(j=0;;++j)
            if(!vis[j]) break;
        sg[i]=j;
    }
}

bool start()
{
    for(int i=0;i<n;++i)
    {
        if(s[i]=='X')
            continue;
        if(i-1>=0 && i+1<n && s[i-1]=='X' && s[i+1]=='X')  ans.push_back(i);
        else if(i-2>=0 && s[i-2]=='X' && s[i-1]=='X')   ans.push_back(i);
        else if(i+2<n && s[i+1]=='X' && s[i+2]=='X')    ans.push_back(i);
    }
    return ans.size()>0;
}

void getSkip()
{
    memset(skip,0,sizeof(skip));
    for(int i=0;i<n;++i)
    {
        if(s[i]=='X')
        {
            for(int j=max(i-2,0);j<=i+2;++j)
                skip[j]=1;
        }
    }
}

int getNim()
{
    int res=0, last=0;
    getSkip();
    for(int i=0;i<n;++i)
    {
        if(skip[i])
        {
            res^=sg[last];
            last = 0;
        }
        else ++last;
    }
    res^=sg[last];
    return res;
}

void run()
{
    static int cas=1;
    memset(s,0,sizeof(s));
    scanf("%s",s);
    n=strlen(s);
    ans.clear();
    printf("Case %d: ",cas++);
    if(start())
    {
        show();
        return;
    }
    if(getNim()==0)
    {
        puts("0");
        return;
    }
    getSkip();
    for(int i=0;i<n;++i)    skip2[i] = skip[i];
    for(int i=0;i<n;++i)
    {
        if(skip2[i]) continue;
        s[i]='X';
        if(getNim()==0)    ans.push_back(i);
        s[i]='.';
    }
    show();
}

int main()
{
    freopen("case.txt","r",stdin);
    build();
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
