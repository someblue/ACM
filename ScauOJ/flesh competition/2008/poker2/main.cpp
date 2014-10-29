#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n,i,j,flag,p;
    char str[100];
    bool vis[100]={0};
    cin>>n;
    str[n]='\0';
    flag=1;
    p=0;
    for(i=1;i<=n;i++)
    {
        while(1)
        {
            if(vis[p]){p++;continue;}
            if(--flag)
            {
                str[p++]='_';
            }
            else
            {
                str[p]=i+'0';
                vis[p++]=1;
                break;
            }
            if(p>=n) p=0;
        }
        flag=2;
    }
    for(i=0;i<n;i++)
    {
        if(i!=0&&i%4==0) cout<<' ';
        cout<<str[i];
    }
    return 0;
}
