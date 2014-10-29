#include <iostream>
#include <cstdio>
#include <windows.h>

using namespace std;

int main()
{
    //freopen("case.txt","r",stdin);
    //freopen("ans.txt","w",stdout);
    char p[30];
    int i;
    for(i=0;i<29;i++)
        scanf("%x",&p[i]);
    p[29]='\0';
    char key[] = "sleepiforest";
    char msg[30];
    int msglen=29,keylen=12;
    for(i=0;i<msglen;i++)
    {
        msg[i]=key[i%keylen]^p[i];
    }
    msg[29]='\0';
    printf("%s",msg);
    system("pause");
    return 0;
}

//ans:" \\<~!~ Forget-Me-Not ~!~>// ";
