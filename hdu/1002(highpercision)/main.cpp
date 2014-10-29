#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#define N 100
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int mod=10000;

struct hp{
//    vector<int> d;
    int d[1000];
    int sz;
    hp() {sz=0;memset(d,0,sizeof(d));}
    void clear() {sz=0;memset(d,0,sizeof(d));}
    friend istream& operator >> (istream& is,hp &a){
        string s;
        is>>s;
        int i,j;
        int t;
        for(i=s.size()-1;i-4>=0;i-=4)
        {
            t=0;
            for(j=3;j>=0;j--)
                t=t*10+s[i-j]-'0';
            a.d[a.sz++]=t;
        }
        if(i>=0)
        {
            int k;
            for(t=0,k=0;k<=i;k++)
            {
                t=t*10+s[k]-'0';
            }
            a.d[a.sz++]=t;
        }
        return is;
    }
    friend ostream& operator << (ostream& os,hp &a){
        for(int i=a.sz-1;i>=0;i--)
            os<<a.d[i];
        return os;
    }
    friend hp operator + (const hp a,const hp b){
        hp c;
        int t=0;
        for(int i=0;i<a.sz||i<b.sz;i++)
        {
            c.d[i]=(a.d[i]+b.d[i]+t)%mod;
            t=(a.d[i]+b.d[i]+t)/mod;
        }
        c.sz = max(a.sz,b.sz);
        return c;
    }
};

void run()
{
    int _,cas=1;
    bool fir;
    cin>>_;
    while(_--)
    {
        hp a,b,c;
        cin>>a>>b;
        c = a+b;
        if(fir) fir=0;
        else cout<<endl;
        printf("Case %d:\n",cas++);
        cout<<a<<" + "<<b<<" = "<<c<<endl;
    }
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
