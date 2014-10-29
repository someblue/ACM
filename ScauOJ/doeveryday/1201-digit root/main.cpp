#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char s[1010],ans[1010];

int main()
{
    int ps,pans;
    while(scanf("%s",s),strcmp(s,"0"))
    {
        strcpy(ans,s);
        while(strlen(ans)>1)
        {
            ps=pans=0;
            s[ps]='0';
            for(;ans[pans]!='\0';pans++)
            {
                s[ps]=ans[pans]+s[ps]-'0';
                if(s[ps]>'9')
                {
                    s[ps]=s[ps]-10;
                    s[++ps]='1';
                }
                //cout<<ans<<endl;
            }
            s[++ps]='\0';
            strcpy(ans,s);
        }
        printf("%s\n",ans);
    }
    return 0;
}
