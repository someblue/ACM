#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int maxi,maxj;
int moun[102][102],len[102][102];
bool vis[102][102];

int max(int a,int b)
{
    return (a>b)?a:b;
}

int max(int a,int b,int c,int d)
{
    return max(max(a,b),max(c,d));
}

int dp(int i,int j)
{
    if(vis[i][j]) return len[i][j];
    vis[i][j]=1;
    if(i==0||i>maxi||j==0||j>maxj) {len[i][j]=0;return 0;}
    int a,b,c,d;
    int &now=moun[i][j];
    a=b=c=d=len[i][j]=-1;
    if(now>moun[i][j+1]) a=dp(i,j+1);
    if(now>moun[i][j-1]) b=dp(i,j-1);
    if(now>moun[i+1][j]) c=dp(i+1,j);
    if(now>moun[i-1][j]) d=dp(i-1,j);
    len[i][j]=max(a,b,c,d);
    if(len[i][j]==-1) return -1;
    len[i][j]++;
    return len[i][j];
}

int main()
{
    freopen("case.txt","r",stdin);

    int i,j;
    int topi,topj,top=0;
    memset(moun,0,sizeof(moun));
    memset(vis,0,sizeof(vis));
    cin>>maxi>>maxj;
    for(i=1;i<=maxi;i++)
        for(j=1;j<=maxj;j++)
        {
            cin>>moun[i][j];
            if(top<moun[i][j])
            {
                topi=i;
                topj=j;
                top=moun[i][j];
            }
        }
    cout<<dp(topi,topj)<<endl;
    return 0;
}
