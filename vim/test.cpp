#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<bitset>
#include<ctime>

using namespace std;

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(int x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

const int maxn=300;
const int inf=1000000000;

int a[maxn],c[maxn],mask[maxn];
int p[30];
int dp[maxn+1][1024];

int main()
{
  int n=get();
  for(int i=0;i<n;i++)
    a[i]=get();
  for(int i=0;i<n;i++)
    c[i]=get();
  int ans=inf;
  for(int i=0;i<n;i++)
    {
      int m=0,t=a[i];
      for(int j=2;j*j<=t;j++)
        if(!(t%j))
          {
            p[m++]=j;
            while(!(t%j))
              t/=j;
          }
      if(t>1)
        p[m++]=t;
      for(int j=0;j<n;j++)
        {
          mask[j]=0;
          for(int k=0;k<m;k++)
            if(!(a[j]%p[k]))
              mask[j]|=1<<k;
        }
      for(int j=0;j<(1<<m)-1;j++)
        dp[0][j]=inf;
      dp[0][(1<<m)-1]=0;
      for(int j=0;j<n;j++)
        {
          for(int k=0;k<(1<<m);k++)
            dp[j+1][k]=inf;
          for(int k=0;k<(1<<m);k++)
            if(dp[j][k]!=inf)
              {
                dp[j+1][k]=min(dp[j+1][k],dp[j][k]);
                dp[j+1][k&mask[j]]=min(dp[j+1][k&mask[j]],dp[j][k]+c[j]);
              }
        }
      ans=min(ans,dp[n][0]+c[i]);
    }
  if(ans==inf)
    ans=-1;
  output(ans);
  return 0;
}
