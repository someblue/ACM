#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100010;
int cas = 1;

int num[N],n;

bool judge(int s,int t)
{
    int win[3], score[3];
    win[1]=win[2]=score[1]=score[2]=0;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=2; j++)
            if(score[j]==t)
            {
                win[j]++;
                score[1]=score[2]=0;
                if(win[j]==s)
                    return 0;
            }

        score[num[i]]++;
    }
    for(int j=1; j<=2; j++)
        if(score[j]==t)
        {
            win[j]++;
            if(win[j]==s)
                return 1;
        }
    return 0;
}

void run()
{
    vector<pii> v;
    int cnt[3];
    cnt[1]=cnt[2]=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",num+i);
        cnt[num[i]]++;
    }
    int x = cnt[num[n-1]];
//    cout << x << endl;
    for(int s=1; s<=x; s++)
    {
        if(x%s) continue;
        int t=x/s;
//        cout << s << ' ' << t << endl;
        if(judge(s,t)) v.push_back(make_pair(s,t));
    }
    printf("%d\n",v.size());
    for(int i=0; i<v.size(); i++)
        printf("%d %d\n",v[i].first, v[i].second);
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
