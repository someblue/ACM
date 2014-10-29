#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("case.txt","r",stdin);
    int n,m,k,num[100][100];
    int i,j;
    cin>>n>>m>>k;
    k%=4;
    switch(k)
    {
    case 0:
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>num[i][j];
        break;
    case 1:
        for(j=n-1;j>=0;j--)
            for(i=0;i<m;i++)
                cin>>num[i][j];
        n+=m;m=n-m;n=n-m;
        break;
    case 2:
        for(i=n-1;i>=0;i--)
            for(j=m-1;j>=0;j--)
                cin>>num[i][j];
        break;
    case 3:
        for(j=0;j<n;j++)
            for(i=m-1;i>=0;i--)
                cin>>num[i][j];
        n+=m;m=n-m;n=n-m;
        break;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<num[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
