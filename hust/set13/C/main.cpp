#include <iostream>
#include <cstring>
using namespace std;
const int N = 1005;
int fi[N];
int sg[N];
bool has[N];
char ans[2][10]={"Nacci","Fibo"};
void build_fibo()
{
    fi[1]=1,fi[2]=2;
    for(int i=3;fi[i-1]<=N;++i)
        fi[i]=fi[i-1]+fi[i-2];
}
void build_sg()
{
    sg[0]=0;
    for(int i=1;i<N;++i)
    {
        memset(has,0,sizeof(has));
        for(int j=1;fi[j]<=i;++j)
            has[sg[i-fi[j]]]=1;
        for(int j=0;j<=i;++j)
            if(!has[j])
            {
                sg[i]=j;
                break;
            }
    }
}
int main()
{
    build_fibo();
    build_sg();
    //for(int i=0;i<20;++i)   cout<<sg[i]<<endl;
    int m,n,p;
    while(cin>>m>>n>>p && !(m==0 && n==0 && p==0))
        cout<<ans[(sg[m]^sg[n]^sg[p])>0]<<endl;
    return 0;
}
