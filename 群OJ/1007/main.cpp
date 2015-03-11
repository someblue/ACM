#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
const int N = 35;

int n;
int mat[N][N];

bool c1() {
    rep(i,n) if(mat[i][i]) return 0;
    return 1;
}
bool c2() {
    rep(i,n) rep(j,n) if(mat[i][j]<0) return 0;
    return 1;
}
bool c3() {
    rep(i,n) rep(j,n) if(mat[i][j]!=mat[j][i]) return 0;
    return 1;
}
bool c4() {
    rep(i,n) rep(j,n) rep(k,n) if(i!=j && i!=k && j!=k) if(mat[i][j]+mat[j][k]<mat[i][k]) return 0;
    return 1;
}

int main()
{
    freopen("case.txt","r",stdin);
    int _;
    cin >> _;
    while(_--) {
        cin >> n;
        rep(i,n) rep(j,n)
            cin >> mat[i][j];
        if(!c1()) puts("1");
        else if(!c2()) puts("2");
        else if(!c3()) puts("3");
        else if(!c4()) puts("4");
        else puts("0");
    }
    return 0;
}
