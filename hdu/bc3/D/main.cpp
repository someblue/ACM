#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int isprm(int x)
{
    if(x==1) return 0;
    if(x==2 || x==3)    return 1;
    for(int i=2;i*i<=x;++i)
        if(x%i==0)  return 0;
    return 1;
}

int force(int n)
{
    if(n==1)    return 0;
    int res=1;
    for(int i=2;i<n;++i)
        if(gcd(i,n)==1)
            res = res*i%n;
    return res;
}

void dabiao()
{
    for(int i=1;i<=2000;++i)
    {
        if(force(i)==1) printf("     ");
        else            printf("%5d",i);
//        printf("%5d",force(i)+1);
//        printf("%5d:%d",force(i),isprm(i));
        if(i%10==0) cout<<endl;
    }
    cout<<"---------------------------------"<<endl;
//    for(int i=1;i<=100;++i)
//    {
//        printf("%5d",isprm(i));
//        if(i%10==0) cout<<endl;
//    }
}

int main()
{
    int n;
    dabiao();
    while(cin>>n)
        cout<<force(n)<<endl;;
    return 0;
}
