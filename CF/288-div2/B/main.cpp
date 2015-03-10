#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

string s;

void run()
{
    int sz = s.size();
    string ans="-1", t;
    int pos=-1;
    char c = s[sz-1];
    for(int i=0; i<sz-1; i++)
    {
        if((s[i]-'0')%2==1) continue;
        if(s[i] < c)
        {
            swap(s[i],s[sz-1]);
            ans = s;
            pos = -1;
            break;
        } else {
            pos = i;
        }
    }
//    cout << s << ' ' << pos << endl;
    if(pos >= 0)
    {
        ans = s;
        swap(ans[pos],ans[sz-1]);
    }
    cout << ans << endl;
}

int main()
{
    while(cin >> s)
        run();
    return 0;
}
