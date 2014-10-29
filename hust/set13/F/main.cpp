#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 25;

int sg[N][N][N];
bool vis[N];

void build_sg()
{
    int L,m,i,j;
    for(m=1;m<=20;++m)
    {
        for(L=1;L<=20;++L)
        {
            sg[m][L][0]=0;
            for(i=1;i<=m;++i)
            {
                memset(vis,0,sizeof(vis));
                for(j=max(0,i-L);j<i;++j)
                    vis[sg[m][L][j]]=1;
                for(j=0;;++j)
                    if(!vis[j])
                    {
                        sg[m][L][i]=j;
                        break;
                    }
            }
        }
    }
}

int main()
{
    build_sg();
    int _;
    int n,m,l;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        int xors = 0;
        while(n--)
        {
            scanf("%d%d",&m,&l);
            xors ^= sg[m][l][m];
        }
        if(xors) puts("No");
        else    puts("Yes");
    }
    return 0;
}
