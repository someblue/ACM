#include <bits/stdc++.h>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 20;
int cas = 1;

string s;

void run()
{
    int sz = s.length();
    int p=0;
    if(s[p]=='9') p=1;
    for(; p<sz; p++)
    {
        if(s[p]>='5') s[p] = '9'-s[p]+'0';
    }
    cout << s << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(cin>>s)
        run();
    return 0;
}
