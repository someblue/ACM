#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[100010];

int main()
{
    //freopen("case.txt","r",stdin);
    int pep,max,min,len,i;
    while(scanf("%s",str)>0)
    {
        pep=max=min=0;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]=='+')
            {
                pep++;
                if(max<pep) max=pep;
            }
            else
            {
                pep--;
                if(min>pep) min=pep;
            }
        }
        cout<<max-min<<endl;
    }
    return 0;
}
