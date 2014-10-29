#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
const int N = 1010;
int k;
char s[N],let[N];
int dp[N][N],len,n,l[N];

void pre()
{
    len = strlen(s);
    n = 0;
    for(int i=0;i<len;++i)
        if(isalpha(s[i]))
        {
            if(isupper(s[i]))
                s[i]='a'+s[i]-'A';
            let[n]=s[i];
            l[n++]=i;
        }
    for(int i=0;i<=n;++i)
        dp[i][i]=dp[i+1][i]=0;
}

int main()
{
    freopen("case.txt","r",stdin);
    int cas=1;
    while(scanf("%d",&k)!=EOF)
    {
        char tc;
        scanf("%c",&tc);
        gets(s);
        pre();
        int ans = 1,pos = 0;
        for(int ll=1;ll<n;++ll)
            for(int i=0;i+ll<n;++i)
            {
                dp[i][i+ll]=dp[i+1][i+ll-1] + (let[i]!=let[i+ll]);
                if(dp[i][i+ll]<=k)
                {
                    int tmp = l[i+ll]-l[i]+1;
                    if(tmp > ans)
                        ans = tmp , pos = l[i];
                    else if(tmp==ans && pos > l[i])
                        pos = l[i];
                }
            }
        printf("Case %d: %d %d\n",cas++,ans,pos+1);
    }
    return 0;
}
