#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1000010
using namespace std;
int d[10][N];

void show(int k,int sz)
{
    for(int i=sz;i>0;i--)
        printf("%d",d[k][i]);
    printf("\n");
}

int cmp(int ok,int k,int sz)
{
    if(!ok) return k;
    for(int i=sz;i>0;i--)
    {
        if(d[k][i]<d[ok][i]) return k;
        if(d[k][i]>d[ok][i]) return ok;
    }
    return ok;
}

int main()
{
    int n,x,kkk;
    while(cin>>n>>x)
    {
        memset(d,0,sizeof(d));
        int i,c;
        int ok=0;
        for(kkk=1;kkk<=9;kkk++)
        {
            d[kkk][1]=kkk;
            c=0;
            for(i=1;i<=n;i++)
            {
                d[kkk][i+1]=(d[kkk][i]*x+c)%10;
                c=(d[kkk][i]*x+c)/10;
            }
//            cout<<kkk<<": "<<d[kkk][n+1]<<" "<<c<<"  ";show(kkk,n);
            if(c==0&&d[kkk][n]!=0&&d[kkk][n+1]==d[kkk][1])
            {
                ok=cmp(ok,kkk,n);
            }
        }
        if(ok) show(ok,n);
        else printf("Impossible\n");
    }
    return 0;
}
