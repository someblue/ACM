#include <iostream>
#include <cstdio>
#define CHECK if(check(ju)){cout<<"NO"<<endl;goto loop;}

using namespace std;

bool check(int *num)
{
    bool vis[9]={0};
    int i;
    for(i=0;i<9;i++)
    {
        int &n=num[i];
        if(vis[n-1]) return 1;
        else vis[n-1]=!vis[n-1];
    }
    return 0;
}

void output(int *num)
{
    int i;
    for(i=0;i<9;i++)
        cout<<*(num+i)<<' ';
    cout<<endl;
    cout<<check(num)<<endl;
}

int main()
{
    freopen("case.txt","r",stdin);
    int sudo[9][9],ju[9];
    int i,j,m,n,T,cnt;
    cin>>T;
    while(T--)
    {
        for(i=0;i<9;i++)
            for(j=0;j<9;j++)
                cin>>sudo[i][j];
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
                ju[j]=sudo[i][j];
            CHECK
        }
        for(j=0;j<9;j++)
        {
            for(i=0;i<9;i++)
                ju[i]=sudo[i][j];
            CHECK
        }
        for(m=0;m<3;m++)
            for(n=0;n<3;n++)
            {
                cnt=0;
                for(i=3*m;i<3*m+3;i++)
                    for(j=3*n;j<3*n+3;j++)
                        ju[cnt++]=sudo[i][j];
                CHECK
            }
        cout<<"YES"<<endl;
        loop:;
    }
    return 0;
}
