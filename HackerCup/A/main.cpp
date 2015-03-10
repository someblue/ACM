#include <bits/stdc++.h>
using namespace std;

char n[20],mx[20],mn[20],t[20];
int cas=1;

void run()
{
    scanf("%s",n);
    strcpy(mx,n);
    strcpy(mn,n);
    for(int i=0; i<strlen(n); i++)
        for(int j=i+1; j<strlen(n); j++)
    {
        strcpy(t,n);
        if(i==0 && t[j]=='0') continue;
        swap(t[i],t[j]);
        if(strcmp(t,mn)<0) strcpy(mn,t);
        if(strcmp(t,mx)>0) strcpy(mx,t);
    }
    printf("Case #%d: %s %s\n",cas++,mn,mx);
}

int main()
{
    freopen("case.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
