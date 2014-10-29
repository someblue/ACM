#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100010;
int cas = 1;

char s[N];
int sum[N][30],k;
#define id(x) (x-'a')

inline bool check(int l,int r)// [l,r)
{
    l--;
//    cout<<l<<' '<<r<<' ';
    for(int i=0;i<26;i++)
        if(sum[r][i]-sum[l][i]>k)
        {
//            cout<<i<<endl;
            return 0;
        }
//    cout<<"ok"<<endl;
    return 1;
}

void run()
{
    scanf("%s",s+1);
    scanf("%d",&k);
    int i,j;
    int sz = strlen(s+1);
//    cout<<sz<<endl;
    for(j=0;j<26;j++)
        sum[0][j]=0;
    for(i=1;i<=sz;i++)
    {
        for(j=0;j<26;j++)   sum[i][j]=sum[i-1][j];
        sum[i][id(s[i])]++;
    }
//    for(i=0;i<=sz;i++)
//    {
//        for(j=0;j<26;j++) cout<<sum[i][j]<<' ';
//        cout<<endl;
//    }
    int p1,p2;
    ll ans = 0;
    for(p1=1,p2=2;p1<=sz;p1++)
    {
        while(p2<=sz && check(p1,p2)) p2++;
//        cout<<p1<<' '<<p2<<endl;
        ans+=p2-p1;
    }
    printf("%I64d\n",ans);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
