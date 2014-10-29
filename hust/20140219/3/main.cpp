#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SN 45

using namespace std;

struct str{
    char s[SN];
    int index;
    friend bool operator < (str a,str b)
    {
        return strcmp(a.s,b.s)<0;
    }
};

str name[N];
char ans[N][SN];

int main()
{
    int i,n,cnt;
    char temp[SN],num[10];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",name[i].s);
        name[i].index=i;
    }
    sort(name,name+n);
//    for(i=0;i<n;i++)
//    {
//        printf("%s\t%d\n",name[i].s,name[i].index);
//    }
    strcpy(ans[name[0].index],"OK");
    strcpy(temp,name[0].s);
    cnt=0;
    for(i=1;i<n;i++)
    {
        strcpy(ans[name[i].index],name[i].s);
        if(strcmp(name[i].s,temp)==0)
        {
            itoa(++cnt,num,10);
            strcat(ans[name[i].index],num);
        }
        else
        {
            cnt=0;
            strcpy(temp,name[i].s);
            strcpy(ans[name[i].index],"OK");
        }
    }
    //print
    for(i=0;i<n;i++)
        printf("%s\n",ans[i]);
    return 0;
}
