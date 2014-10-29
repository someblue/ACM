#include <iostream>
#include <cstdio>

using namespace std;

void print(const int &m,int remain,int *vis,int *ans)
{
    int i;
    if(remain==0)
    {
        for(i=0;i<m-1;i++)
            printf("%d,",ans[i]);
        printf("%d\n",ans[i]);
        return;
    }
    for(i=1;i<=m;i++)
    {
        if(vis[i]) continue;
        ans[m-remain]=i;
        vis[i]=1;
        print(m,remain-1,vis,ans);
        vis[i]=0;
    }
}

int main()
{
    int num[11]={0},ans[11];
    int n;
    cin>>n;
    print(n,n,num,ans);
    return 0;
}
