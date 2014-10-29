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
#define N 100005
using namespace std;
typedef pair<int,int> pii;
const int INF=1000000007;
const double eps=1e-6;

int stk[N][2];
int n,top,a[N],ans[N];

int bs(int x)
{
    int l=0,r=top,m;
    if(x>stk[l][0]) return l;
    if(x<=stk[top-1][0]) return -1;
    while(l<r)
    {
//        cout<<l<<' '<<r<<endl;
        m=(l+r)/2;
        if(stk[m-1][0]>=x && x>stk[m][0])
            return m;
        else if(x <= stk[m][0]) l=m+1;
        else r=m;
    }
    return l;
}

void run()
{
    int i,k;
    for(i=0;i<n;++i) scanf("%d",&a[i]);
    ans[n-1]=-1;
    stk[0][0]=a[n-1];
    stk[0][1]=n-1;
    top=1;
    for(i=n-2;i>=0;--i)
    {
        if(a[i]<stk[top-1][0])
        {
            stk[top][0]=a[i];
            stk[top][1]=i;
            ++top;
            ans[i]=-1;
        }
        else
        {
            k=bs(a[i]);
            if(k==-1) ans[i]=-1;
            else ans[i]=(stk[k][1]-i-1);
        }
    }
    for(i=0;i<n;++i) printf("%d ",ans[i]);
}

int main()
{
    scanf("%d",&n);
        run();
    return 0;
}
