#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 110;
int cas = 1;

//  http://acm.zju.edu.cn/mdj2014/contestInfo.do?contestId=2

char s[N];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s);
        int i,c=1;
        for(i=0;i<n;i++)
        {
            if(s[i]=='0') break;
            c++;
        }
        if(i==n) printf("%d\n",n);
        else printf("%d\n",c);
    }
    return 0;
}
