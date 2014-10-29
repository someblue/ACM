#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 10005;

char s[N],ans[N];

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%s",s);
        ans[0]='\0';
        int t;
        char c;
        t=1,c=s[0];
        int len=strlen(s);
        for(int i=1;i<=len;++i)
        {
            if(s[i]==c)
                ++t;
            else
            {
                if(t==1)    sprintf(ans+strlen(ans),"%c",c);
                else        sprintf(ans+strlen(ans),"%d%c",t,c);
                t=1;c=s[i];
            }
        }
        printf("%s\n",ans);
    }
    return 0;
}
