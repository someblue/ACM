#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define N 100010
using namespace std;
typedef long long ll;
struct node{
    int lc,rc,par;
    bool vis;
    ll type;
}ta[N],tb[N];

ll nowtype;
map<ll,ll> mp;
int cnta[2*N],cntb[2*N];
int na,nb;

void text()
{
    int i;
    cout<<"treeA:"<<endl;
    for(i=1;i<=na;i++)
        cout<<ta[i].lc<<' '<<ta[i].rc<<' '<<ta[i].type<<endl;
    cout<<"treeB:"<<endl;
    for(i=1;i<=na;i++)
        cout<<tb[i].lc<<' '<<tb[i].rc<<' '<<tb[i].type<<endl;
    cout<<"typeA:"<<endl;
    for(i=1;i<nowtype;i++)
        cout<<cnta[i]<<endl;
    cout<<"typeA:"<<endl;
    for(i=1;i<nowtype;i++)
        cout<<cntb[i]<<endl;
}

void bfs(int& n,node* tree,int* cnt)
{
    int i,idx,lc,rc;
    ll type;
    ll lr;
    queue<int> que;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&tree[i].lc,&tree[i].rc);
        if(tree[i].lc==-1)
            tree[i].lc=0;
        else
            tree[tree[i].lc].par = i;
        if(tree[i].rc==-1)
            tree[i].rc=0;
        else
            tree[tree[i].rc].par = i;
        if(!tree[i].lc && !tree[i].rc)
            que.push(i),tree[i].type=1;
    }
//    queue<int> que2(que);
//    cout<<"queue:";
//    while(!que2.empty())
//    {
//        cout<<que2.front()<<' ';
//        que2.pop();
//    }
//    cout<<endl;
    while(!que.empty())
    {
        idx = que.front(); que.pop();
        if(tree[idx].vis)   continue;
        tree[idx].vis = 1;
        if(tree[idx].par)   que.push(tree[idx].par);
        lc = tree[idx].lc;
        rc = tree[idx].rc;
        lr = (tree[lc].type<<20)|tree[rc].type;
        if(mp.find(lr)!=mp.end())
        {
            type = mp[lr];
            cnt[type]++;
            tree[idx].type = type;
        }
        else
        {
            tree[idx].type = nowtype++;
            mp[lr] = tree[idx].type;
            cnt[tree[idx].type]++;
        }
    }
}

void run()
{
    scanf("%d%d",&na,&nb);
    mp.clear();
    memset(cnta,0,sizeof(cnta));
    memset(cntb,0,sizeof(cntb));
    nowtype = 1;
    memset(ta,0,sizeof(ta));
    memset(tb,0,sizeof(tb));
    bfs(na,ta,cnta);
    bfs(nb,tb,cntb);
    int i;
    long long res=0;
    for(i=1;i<nowtype;i++)
        res+=cnta[i]*cntb[i];
    printf("%I64d\n",res);
//    text();
}

int main()
{
//    freopen("in","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)run();
    return 0;
}
