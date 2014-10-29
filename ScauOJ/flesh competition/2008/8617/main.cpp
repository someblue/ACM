#include <iostream>

using namespace std;
typedef long long ll;

ll fact[55];

void get()
{
    fact[1]=1;
    for(int i=2;i<=50;i++)
        fact[i]=fact[i-1]*i;
}

int work(ll x)
{
    int res = 0;
    for(;x;x/=10)
        res+=x%10;
    return res;
}

int main()
{
    get();
    for(int i=1;i<=50;i++)
        cout<<work(fact[i])<<endl;
    return 0;
}
