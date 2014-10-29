#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010

using namespace std;

char input[N],check[N],temp[N];

int main()
{
    int len1,len2,ok,p1,p2;
    do
    {
        gets(input);
        gets(check);
        len1=strlen(input);
        len2=strlen(check);
        p1=p2=0;ok=0;
        for(;p1<len1;p1++)
        {
            if(input[p1]==check[p2])
            {
                p2++;
                if(p2>=len2)
                {
                    ok=1;
                    break;
                }
            }
        }
        printf("%s\n",ok?"Yes":"No");
        //printf("input:%s\ncheck:%s\n",input,check);
    }while(gets(temp)!=0);
    return 0;
}
