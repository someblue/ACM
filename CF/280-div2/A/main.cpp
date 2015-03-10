#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
int cas = 1;


int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    int n,ans,sum,sum2;
    while(cin>>n)
    {
        ans = sum = sum2 = 0;
        while(true)
        {
            if(sum2 > n) break;
            ans ++ ;
            sum += ans;
            sum2 += sum;
        }
        cout << ans-1 << endl;
    }
    return 0;
}
