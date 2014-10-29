#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
bool s[16],e[16];

void output(bool l[16]);

void input()
{
    int i,j;
    char in[5];
    for(i=0;i<4;i++)
    {
        cin>>in;
        //cout<<in<<endl;
        for(j=i*4;j<i*4+4;j++)
        {
            s[j]=in[j-i*4]-'0';
        }
    }
    //output(s);
}

void init(bool l[16])
{
    int i;
    for(i=0;i<16;i++) l[i]=s[i];
}

void change(bool l[16],int k)
{
    int i,r,c;
    r=k/4;c=k%4;
    for(i=c;i<16;i=i+4) l[i]=!l[i];
    for(i=r*4;i<r*4+4;i++) l[i]=!l[i];
    l[k]=!l[k];
}

bool lightcmp(bool l[16])
{
    int i;
    for(i=0;i<16;i++) if(l[i]!=e[i]) break;
    if(i==16) return 1;
    else return 0;
}

int num_i(int k)
{
    unsigned i;
    for(i=0;i<=16;i++) if((1<<i)>k) return i;
}

int enumlight()
{
    unsigned i,j,cnt,maxi;
    bool perform[16],l[16];
    for(i=1;i<=(1<<16);i++)
    {
        init(l);
        maxi=num_i(i);
        for(j=0;j<maxi;j++)
            perform[j]=(i>>j)&1;
        for(j=0;j<maxi;j++)
            if(perform[j])
                change(l,j);
        if(lightcmp(l))
        {
            cnt=0;
            for(j=0;j<maxi;j++)
                if(perform[j]) cnt++;
            return cnt;
        }
    }
    return -1;
}

void output(bool l[16])
{
    int i;
    for(i=0;i<16;i++)
    {
        cout<<l[i]<<' ';
        if((i+1)%4==0) cout<<endl;
    }
}

int main()
{
    freopen("case.txt","r",stdin);

    int c,i;
    cin>>c;
    for(i=0;i<16;i++)e[i]=1;
    while(c--)
    {
        input();
        cout<<enumlight()<<endl;
    }
    return 0;
}
