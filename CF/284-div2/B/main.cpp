#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 3010;
int cas = 1;

map<string,string> mp;
int n,m;
void run()
{
    mp.clear();
    string a,b;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        if(a.length() > b.length())
            mp[a] = b;
        else mp[a]=a;
    }
    cin>>a;
    cout<<mp[a];
    for(int i=1; i<n; i++)
    {
        cin>>a;
        cout<<' '<<mp[a];
    }
    cout << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
