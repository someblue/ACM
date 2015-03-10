#include <bits/stdc++.h>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100010;
int cas = 1;

int w[N][10];
pii que[10][N];
int ql[10], qr[10], ans[10], ans2[10], anslen, l, r;
int n,m,k;

int get_max(int mm)
{
    if(ql[mm] < qr[mm])
        return que[mm][ql[mm]].first;
    else
        return 0;
}

void update()
{
    if(r-l+1 <= anslen) return;
    for(int i=1; i<=m; i++)
        ans[i] = get_max(i);
}

void clear(int mm)
{
    ql[mm]=qr[mm]=0;
}


void push(int mm, int idx, int num)
{
    while(ql[mm]<qr[mm] && que[mm][qr[mm]-1].first < num)
    {
        qr[mm]--;
    }
    que[mm][qr[mm]].first = num;
    que[mm][qr[mm]].second = idx;
    qr[mm]++;
}

void pop(int mm)
{
    while(true)
    {
        int t=0;
        for(int i=1; i<=m; i++)
            t += get_max(i);
        if(t > k)
        {
            l++;
            for(int i=1; i<=m; i++)
                if(que[mm][ql[mm]].second < l)
                    ql[mm]++;
        }
        else break;
    }
}

void run()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d",&w[i][j]);
    for(int i=1; i<=m; i++)
        ans[i] = 0;
    anslen = 0;
    for(int j=1; j<=m; j++)
    {
        clear(j);
        push(j,1,w[1][j]);
    }
    l=1;
    for(r=2; r<=n; r++)
    {
        for(int j=1; j<=m; j++)
        {
            push(j,r,w[r][j]);
            pop(j);
        }
        cout << l << ' ' << r << endl;
        update();
    }
    cout << anslen << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(~scanf("%d%d%d",&n,&m,&k))
        run();
    return 0;
}
