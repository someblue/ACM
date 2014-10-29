#include <iostream>
#include <cstdio>

using namespace std;

long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    long long n;
    scanf("%I64d",&n);
    printf("%I64d",lcm(n*4,n+2)/(n+2));
    return 0;
}
