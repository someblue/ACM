#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
string s[N][2];
int p[N],n;

void run()
{
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>s[i][0]>>s[i][1];
        if(s[i][0]>s[i][1])
            swap(s[i][0],s[i][1]);
    }
    for(i=1;i<=n;i++)
        cin>>p[i];
    string now = s[p[1]][0];
    for(i=2;i<=n;i++)
    {
        if(now<s[p[i]][0])
            now=s[p[i]][0];
        else if(now<s[p[i]][1])
            now=s[p[i]][1];
        else
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
        run();
    return 0;
}
