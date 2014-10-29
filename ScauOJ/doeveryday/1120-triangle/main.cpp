#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int num[30][31];
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(num,0,sizeof(num));
        num[0][1]=1;
        for(i=1;i<n;i++)
            for(j=1;j<=i+1;j++)
                num[i][j]=num[i-1][j-1]+num[i-1][j];
        for(i=0;i<n;i++)
        {
            cout<<num[i][1];
            for(j=2;j<=i+1;j++)
                cout<<' '<<num[i][j];
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
