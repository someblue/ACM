#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long a,b;
    while(scanf("%I64d%I64d",&a,&b)!=EOF)
    {
        if(a<=b)printf("%I64d\n",b-a);
        else printf("%I64d\n",a-b);
    }
    return 0;
}

//C++ 4.5.3 - GNU C++ Compiler with options: -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
//ANSI C 4.5.3 - GNU C Compiler with options: -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE
