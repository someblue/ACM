#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[1010];
int num[1010];

int main()
{
    freopen("case.txt","r",stdin);
    int cnt,i,len,five,temp,first;
    first=0;
    while(scanf("%s",str)!=EOF)
    {
//        if(first){cout<<endl;}
//        else first=1;
        len=strlen(str);
        five=temp=cnt=0;
        for(i=0;i<len;i++)
        {
            if(str[i]!='5')
            {
                five=1;
                temp=temp*10+str[i]-'0';
            }
            else if(five==1)
            {
                five=0;
                num[cnt++]=temp;
                temp=0;
            }
        }
        if(str[len-1]!='5')
            num[cnt++]=temp;
        sort(num,num+cnt);
        for(i=0;i<cnt;i++)
            {
                cout<<num[i];
                if(i!=cnt-1) cout<<' ';
            }
        cout<<endl;
    }
    return 0;
}
