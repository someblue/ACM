#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 110;
int cas = 1;

int a[N],b[N];
int n,m;

bool ok(int x,int y)
{
    return x-y>=-1 && x-y<=1;
}

void run()
{
    for(int i=0;i<n;i++) scanf("%d",a+i);
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d",b+i);
    sort(a,a+n);
    sort(b,b+m);
    int ans = 0;
    for(int i=0,j=0;i<n&&j<m;)
    {
//        cout<<a[i]<<' '<<b[j]<<'\t';
        if(ok(a[i],b[j]))
            ans++,i++,j++;
        else if(a[i]<b[j])
            i++;
        else
            j++;
//        cout<<i<<' '<<j<<endl;
    }
    cout<<ans<<endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
