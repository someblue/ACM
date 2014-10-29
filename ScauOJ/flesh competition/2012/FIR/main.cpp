#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1010

using namespace std;

int f[MAXN][MAXN];

bool ju(int x,int y,int n)
{
    int d,cnt;
    //ºá
    //p1=p2=y;
    cnt=0;d=1;
    while(y-d>=0&&f[x][y-d]==f[x][y])d++,cnt++;
    d=1;
    while(y+d<n&&f[x][y+d]==f[x][y])d++,cnt++;
    if(cnt+1>=5){return 1;}
    //Êú
    //p1=p2=x;
    cnt=0;d=1;
    while(x-d>=0&&f[x-d][y]==f[x][y])d++,cnt++;
    d=1;
    while(x+d<n&&f[x+d][y]==f[x][y])d++,cnt++;
    if(cnt+1>=5){return 1;}
    //Ð±
    cnt=0;d=1;
    while(x-d>=0&&y-d>=0&&f[x-d][y-d]==f[x][y])d++,cnt++;
    d=1;
    while(x+d<n&&y+d<n&&f[x+d][y+d]==f[x][y])d++,cnt++;
    if(cnt+1>=5){return 1;}
    cnt=0;d=1;
    while(x+d<n&&y-d>=0&&f[x+d][y-d]==f[x][y])d++,cnt++;
    d=1;
    while(x-d>=0&&y+d<n&&f[x-d][y+d]==f[x][y])d++,cnt++;
    if(cnt+1>=5){return 1;}
    return 0;
}

int main()
{
    int n,m,i,x,y;
    memset(f,-1,sizeof(f));
    //cin>>n>>m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        f[x-1][y-1]=i&1;
        //cout<<i<<":"<<endl;
        //output(*f,*(f+n),n);
        if(ju(x-1,y-1,n))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"baga"<<endl;
    return 0;
}
