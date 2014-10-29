#include <bits/stdc++.h>
#define N 55

using namespace std;
map<string,int> m;
int fa[N];

int findd(string &s)
{
    if(m.find(s)==m.end()) m[s]=m.size();
    return m[s];
}

int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main()
{
    int _,n,i,j,i1,i2,cas=1;
    bool ok;
    string s1,s2;
    cin>>_;
    while(_--)
    {
        m.clear();ok=1;
        cin>>n;
        for(i=0;i<N;i++) fa[i]=i;
        for(i=0;i<n;i++)
        {
            cin>>s1>>s2;
            //cout<<"s1:"<<s1<<"  s2:"<<s2<<endl;
            if(!ok) continue;
            i1 = findd(s1);
            i2 = findd(s2);
            i1 = find(i1);
            i2 = find(i2);
            if(i1==i2) ok=0;
            else fa[i1]=i2;
        }
        printf("Case %d: %s\n",cas++,ok?"Yes":"No");
    }
    return 0;
}
