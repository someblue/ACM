#include <iostream>
#include <vector>
#define N 100
using namespace std;
const int INF = 1<<28;

int ans;
int av[N];
int v[N];
int a,b,aa,bb;

int cnt()
{
//    cout<<"begin\t";
    int i,l;
    int ans=0;
    for(i=0,l=1;i<a+b;i++)
    {
        if(i+1==a+b || v[i]!=v[i+1])
        {
            ans+=v[i]*l*l;
            l=1;
        }
        else
        {
            l++;
        }
    }
//    cout<<"finish"<<endl;
    return ans;
}

void dfs(int cur,int a,int b)
{
    if(!a&&!b)
    {
        int t=cnt();
        if(t>ans)
        {
            ans=t;
            for(int i=0;i<aa+bb;i++)
                av[i]=v[i];
        }
    }
    else
    {
        if(a)
        {
            v[cur]=1;
            dfs(cur+1,a-1,b);
        }
        if(b)
        {
            v[cur]=-1;
            dfs(cur+1,a,b-1);
        }
    }
}

int main()
{
//    while(cin>>a>>b)
    for(a=10,b=2;b<21;b++)
    {
        aa=a;bb=b;
        ans = -INF;
        dfs(0,a,b);
        //cout<<ans<<endl;
        cout<<a<<' '<<b<<":\t"<<ans<<'\t';
        for(int i=0;i<a+b;i++)
        {
            if(av[i]==1)    cout<<'O';
            else    cout<<'X';
        }
        cout<<endl;
    }
    return 0;
}
