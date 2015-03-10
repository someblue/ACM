#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 110;
int cas = 1;

int n,k;
pii a[N];

void run()
{
    for(int i=1; i<=n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a+1,a+n+1);
    int now = 0;
    vector<int> vi;
    for(int i=1; i<=n; i++)
    {
        now += a[i].first;
        if(now > k) break;
        vi.push_back(a[i].second);
    }
    cout << vi.size() << endl;
    for(int i=0; i<vi.size(); i++)
        cout << vi[i] << ' ';
    cout << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(cin>>n>>k)
        run();
    return 0;
}
