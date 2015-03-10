#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1010;
int cas = 1;

int n,l,ans;

void run()
{
    vector<int> v;
    int x;
    for(int i = 0; i < n; i ++ )
    {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    ans = 2*max(v[0],l-v[n-1]);
    for(int i = 1; i < n; i ++ )
    {
        ans = max(ans, v[i] - v[i-1]);
    }
//    cout << 1.0*ans/2 << endl;
    printf("%.10lf\n",1.0*ans/2);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(cin >> n >> l)
        run();
    return 0;
}
