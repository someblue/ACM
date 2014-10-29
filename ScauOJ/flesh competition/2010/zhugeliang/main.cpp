#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    freopen("case.txt","r",stdin);
    int n,max1,max2,t,i;
    char b,s[10];
    //cin>>n;
    scanf("%d",&n);
    scanf("%c",&b);
//    gets(s);
//    n=0;
//    for(i=0;s[i]!='\0';i++)
//        n=n*10+s[i]-'0';
    max1=max2=t=0;
    for(i=0;i<=n;i++)
    {
        if(i==n)b='1';
        else
            //cin>>b;
            scanf("%c",&b);
        b-='0';
        if(b)
        {
            if(t>max1){max2=max1;max1=t;}
            else if(t>max2){max2=t;}
            t=0;
        }
        else
            t++;
    }
    //cout<<max1<<' '<<max2<<endl;
    printf("%d",max1+max2);
    return 0;
}
