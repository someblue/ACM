#include <iostream>
#define N 1010
using namespace std;

int fa[N];

int find(int x)
{
    return fa[x]==x?x:find(fa[x]);
}

void run()
{
    int n,m,a,b;
    int i;
    cin>>n>>m;
    for(i=1;i<=n;++i)   fa[i]=i;
    while(m--)
    {
        cin>>a>>b;
        a=find(a);
        b=find(b);
        if(a!=b)    fa[a]=fa[b];
    }
    int ans=0;
    for(i=1;i<=n;++i)   if(fa[i]==i)    ans++;
    cout<<ans<<endl;
}

int main()
{
    int _;
    cin>>_;
    while(_--)
        run();
    return 0;
}
