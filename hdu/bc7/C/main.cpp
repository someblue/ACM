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
const int N = 1000;
double dp[N];

void build(int m,int n)
{
    dp[0]=1.0;
    for(int i=1;i<=n;i++)
    {
        double tmp = 0.0;
        for(int j=max(0,i-m);j<i;j++)
            tmp += dp[j];
        dp[i] = tmp/m;
    }

}
void run()
{

}

int main()
{
//    freopen("case.txt","r",stdin);
    int m,n;
    while(cin>>m>>n)
    {
        build(m,n);
        cout<<dp[n]<<endl;
    }
    return 0;
}
