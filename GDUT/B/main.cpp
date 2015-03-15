/*------------
2015广工校赛决赛B题
完美串
-------------*/
#include <bits/stdc++.h>
#define MAX(x,y) if(x<(y)) x=(y);
using namespace std;
const int N = 1010;
char s1[N], s2[N];
int dp[N][N], n;
void get_s2() {
    for(int i=1; i<=n; i++) {
        s2[n+1-i] = (s1[i]=='1'?'0':'1');
    }
}
int LCS() {
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++) {
            if(s1[i+1]==s2[j+1]) MAX(dp[i+1][j+1], dp[i][j]+1);
            MAX(dp[i+1][j], dp[i][j]);
            MAX(dp[i][j+1], dp[i][j]);
        }
//    for(int i=1; i<=n; i++) {
//        for(int j=0; j<=n; j++) cout << dp[i][j] << ' ';
//        cout << endl;
//    }
    return dp[n][n];
}

void test() {
    scanf("%s%s", s1+1, s2+1);
    n = strlen(s1+1);
    cout << LCS() << endl;
}

int main()
{
//    while(true)
//        test();
    int _;
    scanf("%d", &_);
    while(_--) {
        scanf("%d", &n);
        scanf("%s", s1+1);
        get_s2();
        int len = LCS();
        printf("%d\n", n-len);
    }
    return 0;
}
