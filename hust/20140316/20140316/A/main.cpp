#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#define VI vector<int>
#define N 60
#define M 210
const int INF=0x3FFFFFFF;
typedef long long ll;
using namespace std;
int num[N][N],p[N],n,m;
int cntline(int mar[],int line,int c)
{
//    sort(num[line],num[line]+n);
    sort(mar,mar+n);
    int i,res=0;
    for(i=0;i<n;i++,c++)
    {
        //res+=abs(c-num[line][i]);
        res+=abs(c-mar[i]);
    }
    return res;
}
int solve()
{
    int i,j,ans=INF,temp,l;
    for(i=1;i+n-1<=m;i++)
    {
        temp=0;
        for(j=1;j<=n;j++)
        {
            //temp+=cntline(j,i);
            temp+=cntline(num[j],j,i);
        }
        //if(temp<ans) l=i;
        ans=min(ans,temp);
    }
    //cout<<l<<endl;
    return ans;
}
void printmatrix()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
            cout<<num[i][j]<<' ';
        cout<<endl;
    }
}
void run()
{
    int x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(num,0,sizeof(num));
        memset(p,0,sizeof(p));
//        scanf("%d",&x);
//        scanf("%d",&num[x][p[x]++]);
        while(scanf("%d%d",&x,&y),!(x==0&&y==0))
        {
            num[x][p[x]++]=y;
        }
        printf("%d\n",solve());
        printmatrix();
    }
}

int main()
{
    run();
    return 0;
}

/*
WA
*/

