#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 210

using namespace std;

char s[N],buf[N];
struct expcoe{
    long long exp,coe;
    friend bool operator < (expcoe a,expcoe b)
    {
        return a.exp>b.exp;
    }
}ec[N];
int pec,first;

//int getbuf(int &ps)
//{
//    if(s[ps]=='\0'||s[ps]=='\n') return 0;
//    int pbuf=0;
//    char c=s[ps++];
//    //if(c!='+')
//        s[pbuf++]=c;
//    while(1)
//    {
//        if(s[ps]=='+'||s[ps]=='-') {buf[pbuf]='\0';return 1;}
//        if(s[ps]=='\0'||s[ps]=='\n') {buf[pbuf]='\0';return 1;}
//        buf[pbuf++]=s[ps++];
//    }
//}

int getbuf(int &ps)
{
    if(s[ps]=='\0'||s[ps]=='\n') return 0;
    int pbuf,i;
    pbuf=1;
    buf[0]=s[ps++];
    while(s[ps]!='+'&&s[ps]!='-'&&s[ps]!='\0'&&s[ps]!='\n')
        buf[pbuf++]=s[ps++];
    buf[pbuf]='\0';
    if(buf[0]=='+')
    {
        for(i=1;i<=pbuf;i++)
            buf[i-1]=buf[i];
    }
    //if(s[ps]=='\0'||s[ps]=='\n') return 0;
    return 1;
}

int findexp(long long k)
{
    int i;
    for(i=0;i<pec;i++)
        if(ec[i].exp==k)
            return i;
    ec[pec].exp=k;
    return pec++;
}

void printcoe(long long coe)
{
    if(coe>0&&first==0) printf("+");
    if(first==1) first=0;
    if(coe==1) return;
    if(coe==-1){printf("-");return;}
    printf("%I64d",coe);//-------------------------
}

void print()
{
    int i;first=1;
    for(i=0;i<pec;i++)
    {
        if(ec[i].coe==0)
            continue;
        if(ec[i].exp==0)
        {
            printcoe(ec[i].coe);
        }
        else if(ec[i].exp==1)
        {
            printcoe(ec[i].coe);
            printf("X");
        }
        else
        {
            printcoe(ec[i].coe);
            printf("X^%I64d",ec[i].exp);//------------------
        }
    }
    printf("\n");
}

int main()
{
    freopen("in","r",stdin);
    int ps,index;
    long long exp,coe;
    char tc;
    while(gets(s)!=NULL)
    {
        memset(ec,0,sizeof(ec));
        ps=0;pec=0;
//        printf("s:%s\n",s);
        while(getbuf(ps))
        {
//            printf("%s\t",buf);
            if(strstr(buf,"X")==NULL)
            {
                if(strstr(buf,"-X")!=NULL) coe=-1;
                else if(strstr(buf,"+X")!=NULL) coe=1;
                else sscanf(buf,"%I64d",&coe);//-------------------
                index=findexp(0);
                exp=0;
            }
            else if(strstr(buf,"^")==NULL)
            {
                if(strstr(buf,"-X")!=NULL) coe=-1;
                else if(strstr(buf,"+X")!=NULL) coe=1;
                else sscanf(buf,"%I64d",&coe);//---------------------
                index=findexp(1);
                exp=1;
            }
            else
            {
                sscanf(buf,"%I64d%c%c%I64d",&coe,&tc,&tc,&exp);//-----------------------
                if(strstr(buf,"-X")!=NULL) coe=-1;
                else if(strstr(buf,"+X")!=NULL) coe=1;
                index=findexp(exp);
            }
//            printf("%d %d %d\n",coe,exp,index);
            ec[index].coe+=coe;
        }
        sort(ec,ec+pec);
//        for(i=0;i<pec;i++)
//            printf("%d\n",ec[i].exp);
        print();
    }
    return 0;
}
