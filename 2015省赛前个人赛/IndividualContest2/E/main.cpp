#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
#define SZ size
#define rep(i,l,r) for(i=(l);i<(r);i++)
#define per(i,l,r) for(i=(r)-1;i>=l;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long ull;
const int INF = 1e9;
const double eps = 1e-6;
const int LEN = 1000010;
const int N = 100010;
const int x = 12321;
int cas = 1;

int n;
char s[LEN], name[N][15], code[N][15];
map<ull, int> idx, cnt;

ull H[20];
inline ull hash_value(char *s, int t)
{
    H[0] = 0;
    for(int i=0; i<10; i++) {
        H[i+1] = H[i]*x + s[i+t] - 'a';
    }
    return H[10];
}

void run()
{
    idx.clear();
    cnt.clear();
    scanf("%s",s);
    int i;
    scanf("%d",&n);
    rep(i,0,n) {
        scanf("%s%s",name[i], code[i]);
        ull h = hash_value(code[i], 0);
//        cout << "codei -> " << h << endl;
        cnt[h] = 0;
        idx[h] = i;
    }
    int len = strlen(s);
//    cout << "len = " << len << endl;
    rep(i,0,len-9) {
        ull h = hash_value(s, i);
//        cout << "str" << i << " -> " << h << endl;
        if(cnt.count(h))
            ++cnt[h];
    }
    ull h; int mx, tmp;
    mx = tmp = 0;
    for(map<ull,int>::iterator it = cnt.begin(); it!=cnt.end(); it++) {
//        cout << (*it).se << ' ';
        if((*it).se > mx) {
            mx = (*it).se;
            tmp = 0;
            h = (*it).fi;
        } else if((*it).se == mx) {
            tmp++;
        }
    }
//    cout << endl;
    if(tmp || mx==0) {
        puts("No-solution!");
    } else {
        puts(name[idx[h]]);
    }
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
