#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100010;
int cas = 1;

int pos_to_idx[2][N], idx_to_pos[2][N], num[N], n, cnt[2];

int pos(int k, int now, int t)
{
    int idx = pos_to_idx[k][now];
    return idx+t>n?INF:idx_to_pos[k][idx+t];
}

int judge(int t)
{
    int now=0, sa=0, sb=0;
    while(true)
    {
        int a = pos(0, now, t);
        int b = pos(1, now, t);
        if(a<b) now=a, sa++;
        else now=b, sb++;
        cout << t << ' ' << a << ' ' << b << ' ' << now << endl;
        Sleep(500);
        if(a==INF && b==INF) return 0;
        if(a==n) return sa>sb?sa:0;
        if(b==n) return sa<sb?sb:0;
    }
}

void run()
{
    for(int i=1; i<=n; i++)
        scanf("%d",num+i),num[i]--;
    pos_to_idx[0][0] = pos_to_idx[1][0] = idx_to_pos[0][0] = idx_to_pos[1][0] = 0;
    for(int i=1; i<=n; i++)
    {
        pos_to_idx[num[i]][i]=pos_to_idx[num[i]][i-1]+1;
        idx_to_pos[num[i]][pos_to_idx[num[i]][i]] = i;
        pos_to_idx[!num[i]][i]=pos_to_idx[!num[i]][i-1];
    }
    cnt[0] = pos_to_idx[0][n];
    cnt[1] = pos_to_idx[1][n];
    cout << "pos to idx:" << endl;
    for(int i=1; i<=n; i++) printf("%d ",pos_to_idx[0][i]); cout<<endl;
    for(int i=1; i<=n; i++) printf("%d ",pos_to_idx[1][i]); cout<<endl;
    cout << "idx to pos:" << endl;
    for(int i=1; i<=n; i++) printf("%d ",idx_to_pos[0][i]); cout<<endl;
    for(int i=1; i<=n; i++) printf("%d ",idx_to_pos[1][i]); cout<<endl;
    cout << cnt[0] << ' ' << cnt[1] << endl;
    vector<pii> ans;
    int mx = max(cnt[0],cnt[1]);
    for(int t=1,s; t<=mx; t++)
    {
        if(s=judge(t))
            ans.push_back(make_pair(s,t));
    }
    sort(ans.begin(), ans.end());
    printf("%d\n",ans.size());
    for(int i=0; i<ans.size(); i++)
        printf("%d %d\n",ans[i].first, ans[i].second);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
