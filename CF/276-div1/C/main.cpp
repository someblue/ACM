#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1000010;
int cas = 1;

int s[N],t[N];
int len,k,d;

void shuff(int l,int k,int d)
{
    copy(s+l,s+l+k,t+l);
//    for(int i=l;i<l+k;i++) cout<<t[i]; cout<<endl;
    int p = l;
    for(int i=0;i<d;i++)
    {
        for(int j=l+i;j<l+k;j+=d)
            s[p++]=t[j];
    }
}

void run(int len,int k,int d)
{
    for(int i=0;i<len;i++) s[i]=i;
//    shuff(0,len,d);
    for(int i=0;i<=len-k;i++)
    {
        shuff(i,k,d);
    }
    for(int i=0;i<len;i++) cout<<s[i];
//    cout<<endl;
}

int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
//    for(int i=0;i<10;i++) s[i]=i;
//    while(cin>>len>>k>>d)
    for(len=5;len<=8;len++)
    {

        for(k=1;k<=len;k++)
        {
            for(d=1;d<=k;d++)
                run(len,k,d),cout<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
