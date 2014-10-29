#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 1000

using namespace std;

int div_num[1010],num[1010];

void creat_div_table()
{
    int i,j;
    for(i=1;i<=MAX;i++)
    {
        for(j=1;i*j<=MAX;j++)
            div_num[i*j]++;
    }
}

void enum_num(int *s,int *e,int start_num)
{
    while(s<e)
        *(s++)=start_num++;
}

void output(int *s,int *e)
{
    while(s<e)
        cout<<*(s++)<<' ';
    cout<<endl;
}

void output(int *s,int *e,int num_line)
{
    while(s<e)
    {
        if(s+num_line<=e)
            output(s,s+num_line);
        else
            output(s,e);
        s+=num_line;
    }
}

bool cmp(int i,int j)
{
    if(div_num[i]<div_num[j]||(div_num[i]==div_num[j]&&i>j)) return 1;
    return 0;
}

int main()
{
    freopen("case.txt","r",stdin);
    memset(div_num,0,sizeof(div_num));
    enum_num(num+1,num+1+MAX,1);
    creat_div_table();
    sort(num+1,num+1+MAX,cmp);
    int T,n,i;
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>n;
        printf("Case %d: %d\n",i,num[n]);
    }
    return 0;
}
