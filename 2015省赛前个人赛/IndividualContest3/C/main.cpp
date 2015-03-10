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
const int INF = 1e9;
const double eps = 1e-6;
int cas = 1;

const int maxn=1005;
int wa[maxn],wb[maxn],wv[maxn],ww[maxn];
int sa[maxn],r[maxn];
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++)ww[i]=0;
    for(i=0;i<n;i++)ww[x[i]=r[i]]++;
    for(i=1;i<m;i++)ww[i]+=ww[i-1];
    for(i=n-1;i>=0;i--)sa[--ww[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p){
        for(p=0,i=n-j;i<n;i++)y[p++]=i;
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        for(i=0;i<n;i++)wv[i]=x[y[i]];
        for(i=0;i<m;i++)ww[i]=0;
        for(i=0;i<n;i++)ww[wv[i]]++;
        for(i=1;i<m;i++)ww[i]+=ww[i-1];
        for(i=n-1;i>=0;i--)sa[--ww[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n){
//    cout<<"3"<<endl;
    int i,j,k=0;
    for(i=1;i<=n;i++)rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
    for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}
char s[maxn];

void run() {
    scanf("%s", s);
    int len = strlen(s);
    for(int i=0; i<len; i++) r[i]=s[i]+1;
    r[len]=0;
    da(r, sa, len+1, 256);
    calheight(r, sa, len);
    int ans = 0;
    for(int i=1; i<=len; i++) ans += len - sa[i] - height[i];
    cout << ans << endl;
}

int main() {
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d", &_);
    while(_--)
        run();
    return 0;
}
