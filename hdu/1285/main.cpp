#include <bits/stdc++.h>
#define N 510
using namespace std;
typedef vector<int> VI;
typedef long long ll;

struct line{
    int u,v,p;
};
vector<line> l;
int in[N],next[N];

void run()
{
    int n,m,i,e;
    bool end;
    line t;
    while(cin>>n>>m)
    {
        queue<int> ans;
        l.clear();
        memset(next,-1,sizeof(next));
        memset(in,0,sizeof(in));
        for(i=0;i<m;i++)
        {
            cin>>t.u>>t.v;
            in[t.v]++;
            t.p = next[t.u];
            next[t.u] = l.size();
            l.push_back(t);
        }
        end=0;
        while(!end)
        {
            end=1;
            for(i=1;i<=n;i++)
            {
                if(!in[i])
                {
                    ans.push(i);
                    in[i]=-1;
                    for(e=next[i];e!=-1;e=l[e].p)  in[l[e].v]--;
                    end=0;
                    break;
                }
            }
        }
        if(ans.size()<n) cout<<"cycle"<<endl;
        else
        {
            cout<<ans.front();
            ans.pop();
            while(!ans.empty())
            {
                cout<<' '<<ans.front();
                ans.pop();
            }
            cout<<endl;
        }
    }
}

int main()
{
    freopen("in","r",stdin);
    ios::sync_with_stdio(0);
    run();
    return 0;
}
