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

string s, t, ans;
int sz;

void f(char a)
{
    char b = '9'-a+'0';
    t = s;
    for(int i=0; i<sz; i++)
        if(t[i]==a)
            t[i]=b;
    if(t[0]=='0') return;
    if(t<ans)
        ans=t;
}

void run()
{
    sz = s.length();
    ans = s;
    for(int i=0; i<=9; i++)
        f(i+'0');
    cout << ans << endl;
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
