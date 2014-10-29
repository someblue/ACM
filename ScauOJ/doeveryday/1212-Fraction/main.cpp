#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    char s[100];
    int a,b,i;
    while(gets(s))
    {
        a=0;b=1;
        for(i=2;s[i]!='\0';i++)
            a=10*a+s[i]-'0';
        while(b*=10,a/b);
        printf("%d/%d\n",a/gcd(a,b),b/gcd(a,b));
    }
    return 0;
}
