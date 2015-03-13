#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int _, n;
    ll a, b, mx;
    cin >> _;
    while(_--) {
        cin >> n;
        mx = 0;
        while(n--) {
            cin >> a >> b;
            mx = abs(a-b);
        }
        cout << mx << endl;
    }
    return 0;
}
