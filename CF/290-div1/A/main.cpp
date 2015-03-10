#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 110;
int cas = 1;

int n;
int g[N][N], in[N], out[N];
bool flag;
string s[N];
queue<int> que;
vector<int> ans;

void init()
{
    flag = 0;
    memset(g,0,sizeof(g));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    ans.clear();
    while(!que.empty()) que.pop();
}

void add(int u, int v)
{
    g[u][v] = 1;
    out[u]++;
    in[v]++;
}

void cmp(string s1, string s2)
{
    int sz = min(s1.size(), s2.size()), i;
    for(i=0; i<sz; i++)
        if(s1[i]!=s2[i])
        {
//            cout << "add: " << s1[i] << ' ' << s2[i] << endl;
            if(!g[s1[i]-'a'][s2[i]-'a'])
                add(s1[i]-'a', s2[i]-'a');
            return;
        }
    if(i >= s2.size())
        flag = 1;
}

void topo()
{
    for(int i=0; i<26; i++)
        if(!in[i])
            que.push(i);
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        ans.push_back(u);
        for(int v=0; v<26; v++)
            if(g[u][v])
            {
                in[v]--;
                if(in[v]==0)
                    que.push(v);
            }
    }
}

void run()
{
    init();
    for(int i=0; i<n; i++)
        cin >> s[i];
    for(int i=1; i<n; i++)
        cmp(s[i-1], s[i]);
    if(flag)
    {
        cout << "Impossible" << endl;
        return;
    }
    topo();
    if(ans.size() < 26) cout << "Impossible" << endl;
    else
    {
        for(int i=0; i<ans.size(); i++)
            cout << (char)('a'+ans[i]);
        cout << endl;
    }
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(cin >> n)
        run();
    return 0;
}
