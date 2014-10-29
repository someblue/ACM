#include <iostream>

using namespace std;
const int N = 1010;

int n,m,k;
int a[N];

inline int cnt(int x)
{
    int res = 0;
    for(int i=0;i<n;i++)
        if(x&(1<<i))
            res++;
    return res;
}

void run()
{
    int i,ans=0;
    for(i=0;i<=m;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
    {
        int x = a[i]^a[m];
        if(cnt(x)<=k)
            ans++;
    }
    cout<<ans<<endl;
}

int main()
{
    while(cin>>n>>m>>k)
        run();
    return 0;
}
