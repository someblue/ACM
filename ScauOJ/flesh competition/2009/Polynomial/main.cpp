#include <iostream>
#define N 15

using namespace std;

int main()
{
    int n,m,ans,anstemp,a[N];
    int i,j;
    cin>>n>>m;
    for(i=0;i<=n;i++)
        cin>>a[i];
    ans=0;
    for(i=m;i<=n;i++)
    {
        anstemp=1;
        for(j=i;j>i-m;j--)
            anstemp*=j;
        ans+=a[i]*anstemp;
    }
    cout << ans << endl;
    return 0;
}
