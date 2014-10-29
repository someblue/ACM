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
const int N = 1;

int dif_force(int x)
{
    int a[20],len;
    len=0;
    for(;x;x/=10)
        a[len++]=x%10;
    int odd=0,even=0;
    for(int i=0;i<len;++i)
    {
        if(i&1) odd+=a[i];
        else even+=a[i];
    }
    return even-odd;
}

int dif_math(int x)
{
    return x%11;
}

int f(int n)
{
    int cnt1=0,cnt2=0;
    for(int x=1;x<=n;++x)
    {
        if(dif_force(x)==3) cnt1++;
        if(dif_math(x)==3) cnt2++;
    }
//    cout<<n<<": "<<cnt1<<' '<<cnt2<<endl;
    return cnt2-cnt1;
}

void run()
{

}

void test()
{
    for(int i=1;i<=100;++i)
    {
        cout<<i<<": "<<dif_force(i)<<' '<<dif_math(i)<<endl;
    }
    cout<<"finish"<<endl;
    int n,dif=0;
    for(n=1;n<=3000;++n)
    {
        int t=f(n);
        if(t>dif)   cout<<n<<' '<<n/11<<' '<<n%11<<endl;
        dif=t;
    }
}

int main()
{
    test();
//    freopen("case.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
