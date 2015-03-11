#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 55;

int t[N];
pii p[N];
int rev(int x) {
    int l=0;
    for(;x;x/=10) t[l++]=x%10;
    int res=0;
    for(int i=0; i<l; i++) res=res*10+t[i];
    return res;
}
int main()
{
    int _;
    cin >> _;
    while(_--) {
        int a, b;
        cin >> a >> b;
        for(int i=0; i+a<=b; i++)
            p[i].se = i+a, p[i].fi = rev(i+a);
        sort(p,p+b-a+1);
        cout << p[0].se;
        for(int i=1; i+a<=b; i++)
            cout << ' ' << p[i].se;
        cout << endl;
    }
    return 0;
}
