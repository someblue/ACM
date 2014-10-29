#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t,a,b,ok;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d",&a,&b);
        if(a==1||b==1) ok=0;
        else if(((a&1)==0)||((b&1)==0)) ok=1;
        else ok=0;
        printf("%s\n",(ok==1?"Yes":"No"));
    }
    return 0;
}
