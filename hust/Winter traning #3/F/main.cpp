#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000000;

ll n,k;
int Q,t;
ll p[55];
int q[55],sz,q1[55],num,ans;

int main()
{
//    freopen("case.txt","r",stdin);
    scanf("%lld%d",&n,&Q);
    sz = 0;
    num = 1;
    ll tn = n;
    for(int i=2; i<=N; i++)
    {
        if(n%i == 0)
        {
            p[sz] = i;
            while(n%i==0)
                {n/=i;q[sz]++;}
            sz++;
        }
    }
    if(n!=1) {p[sz]=n;q[sz]++;sz++;}
    for(int i=0; i<sz; i++) num*=q[i]+1;
    n = tn;
    while(Q--)
    {
        scanf("%d%lld",&t,&k);
        ans = 1;
        if(t==1)
        {
            for(int i=0; i<sz; i++)
            {
                while(k%p[i] == 0)
                    {k/=p[i]; q1[i]++;}
                ans *= (q1[i]<q[i]?q1[i]:q[i]) + 1;
            }
        } else
        {
            if(n%k) ans = 0;
            else
            {
                k = n/k;
                for(int i=0; i<sz; i++)
                {
                    while(k%p[i] == 0)
                        {k/=p[i]; q1[i]++;}
                    ans *= q1[i] + 1;
                }
            }
            if(t==3)
                ans = num - ans;
        }
        for(int i=0; i<sz; i++) q1[i]=0;
        printf("%d\n",ans);
    }
    return 0;
}
