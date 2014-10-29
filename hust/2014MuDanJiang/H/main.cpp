#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
typedef unsigned long long ll;

char s[N],query[N];
int p,sz,qsz;

struct _node{
    int val_l,val_r;
    map<ll,int> mp;
    void clear()
    {
        val_l=val_r=0;
        mp.clear();
    }
}node[N];
int cnt;

ll readname(char *s,int sz,int &l,int &r)
{
    l=p++;
    ll seed = 13131313;
    ll hash = 0;
    while(p<sz && s[p]!='"')
        hash = hash*seed+s[p++];
    r=p++;
    return hash&0x7FFFFFFFFFFFFFFF;
//    cout<<l<<' '<<r<<' '<<s[l]<<' '<<s[r]<<endl;

}

void prints(int l,int r)
{
    while(l<=r && l<sz) putchar(s[l++]);
    puts("");
}

void build(int root)
{
    node[root].val_l=p++;
    if(s[p]=='}') goto bk;
    while(p<sz)
    {
        int l,r;
        ll u = readname(s,sz,l,r);
//        string key(s,l,r-l+1);
//        cout<<l<<' '<<r<<' '<<root<<' '<<key<<endl;
        node[root].mp[u]=cnt;
//        cout<<node[root].mp[key]<<endl;
        node[cnt++].clear();
        p++; // :
        if(s[p]=='{')
            build(cnt-1);
        else
            readname(s,sz,node[cnt-1].val_l,node[cnt-1].val_r);
        if(s[p]=='}') break;
        else p++; // ,
    }
    bk:
    node[root].val_r=p++;
}

void getans(int root,int &ansl,int &ansr)
{
    int l,r;
    while(true)
    {
        ll u = readname(query,qsz,l,r);
//        string str(query,l,r-l+1);
        if(node[root].mp.find(u)!=node[root].mp.end())
            root=node[root].mp[u];
        else
        {
            root=-1;
            break;
        }
        if(query[p]!='.') break;
        p++;
    }
    if(root==-1) ansl=ansr=-1;
    else ansl=node[root].val_l,ansr=node[root].val_r;
}

void run()
{
//    scanf("%s",s);
    gets(s);
    p=0,sz=strlen(s);
    node[0].clear();
    cnt=1;
    build(0);
    int q;char c;
    scanf("%d",&q);
    scanf("%c",&c);
    while(q--)
    {
//        scanf("%s",query);
        gets(query);
        qsz=strlen(query);
        p=0;
        int l,r;
        getans(0,l,r);
        if(l==-1)
            puts("Error!");
        else
            prints(l,r);
    }
//    cout<<endl;
//    for(map<string,int>::iterator it=node[0].mp.begin(); it!=node[0].mp.end(); it++)
//        cout<<it->first<<' '<<it->second<<endl;
}

void test()
{
    scanf("%s",s);
    p=0;
    prints(0,5);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
//    test();
    int _;char c;
    scanf("%d",&_);
    scanf("%c",&c);
    while(_--)
        run();
    return 0;
}
