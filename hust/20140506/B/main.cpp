#include <iostream>
#include <cstdio>
#include <cstring>
#define N 110
using namespace std;
char s[N][2*N];

void run ()
{
    int n,m,ans;
    scanf("%d%d",&n,&m);
    getchar();
    int i,j;
    bool ok;
    for(i=1;i<=n;i++)    gets(s[i]);
//    for(i=1;i<=n;i++)    cout<<i<<": "<<s[i]<<endl;
    ans=n;
    while(true)
    {
        if(ans&1) break;
        ok=1;
        for(i=1,j=ans;i<j;i++,j--)
        {
            if(strcmp(s[i],s[j])!=0)
            {
                ok=0;
                break;
            }
        }
        if(ok) ans/=2;
        else break;
    }
    cout<<ans<<endl;
}

int main()
{
    run();
    return 0;
}
