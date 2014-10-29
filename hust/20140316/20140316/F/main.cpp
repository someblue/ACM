#include <iostream>
#include <cstdio>
#include <cstring>
#define N 110

using namespace std;

int num[N][N];
char s[N];

int dif(int a,int b)
{
    if(a<=b) return 0;
    else return a-b;
}
void print(int n,int m)
{
    int i,j;
    for(i=1;i<=n;i++)
    {

        for(j=1;j<=m;j++)
            cout<<num[i][j]<<' ';
        cout<<endl;
    }
}

int main()
{
    int n,m,i,j;
    char c;
    memset(num,0,sizeof(num));
    scanf("%d%d",&n,&m);
    c=getchar();
    for(i=1;i<=n;i++)
    {
        gets(s);
        //puts(s);
        for(j=1;j<=m;j++)
            num[i][j]=s[j-1]-'0';
    }
    //print(n,m);
    int res;
    res=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(num[i][j]) res+=2;
            res+=dif(num[i][j],num[i-1][j]);
            res+=dif(num[i][j],num[i+1][j]);
            res+=dif(num[i][j],num[i][j-1]);
            res+=dif(num[i][j],num[i][j+1]);
        }
    }
    printf("%d\n",res);
    return 0;
}

/*
AC
*/
