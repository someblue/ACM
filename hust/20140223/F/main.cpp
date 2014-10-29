#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 210

using namespace std;

char s[N],buf[N];
int exp[N],coe[N];
struct expcoe{
    int exp,coe;
    friend bool operator < (expcoe a,expcoe b)
    {
        return a.exp>b.exp;
    }
}ec[N];
int pec,first,ansis0;

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

int findexp(int k)
{
    int i;
    for(i=0;i<pec;i++)
        if(ec[i].exp==k)
            return i;
    ec[pec].exp=k;
    return pec++;
}

void printcoe(int coe)
{
    if(coe>0&&first==0) printf("+");
    if(first==1) first=0;
    if(coe==1) return;
    if(coe==-1){printf("-");return;}
    printf("%d",coe);
}

void print()
{
    int i;first=1;
    for(i=0;i<pec;i++)
    {
        if(ec[i].coe==0)
        {
//            cout<<'a'<<endl;
            continue;
        }
        if(ec[i].exp==0)
        {
            ansis0=0;
//            cout<<'b'<<endl;
//            printcoe(ec[i].coe);
            int c=ec[i].coe;
            if(c>0&&first==0) printf("+");
            if(first==1) first=0;
            printf("%d",c);
        }
        else if(ec[i].exp==1)
        {
            ansis0=0;
//            cout<<'c'<<endl;
            printcoe(ec[i].coe);
            printf("X");
        }
        else
        {
            ansis0=0;
//            cout<<'d'<<endl;
            printcoe(ec[i].coe);
            printf("X^%d",ec[i].exp);
        }
    }
    if(ansis0) printf("0");
    printf("\n");
}

int main()
{
    freopen("in","r",stdin);
    int ps,index;
    int exp,coe;
    char tc;
    while(gets(s)!=NULL)
    {
        memset(ec,0,sizeof(ec));
        ps=0;pec=0;ansis0=1;
//        printf("s:%s\n",s);
        while(getbuf(ps))
        {
            printf("%s\t",buf);
            if(strstr(buf,"X")==NULL)
            {
                if(strstr(buf,"-X")!=NULL) coe=-1;
                else if(strstr(buf,"+X")!=NULL||s[0]=='X') coe=1;
                else sscanf(buf,"%d",&coe);
                index=findexp(0);
                exp=0;
            }
            else if(strstr(buf,"^")==NULL)
            {
                if(strstr(buf,"-X")!=NULL) coe=-1;
                else if(strstr(buf,"+X")!=NULL||s[0]=='X') coe=1;
                else sscanf(buf,"%d",&coe);
                index=findexp(1);
                exp=1;
            }
            else
            {
                if(s[0]=='X') sscanf(buf,"%c%c%d",&tc,&tc,&exp);
                else sscanf(buf,"%d%c%c%d",&coe,&tc,&tc,&exp);
                if(strstr(buf,"-X")!=NULL) coe=-1;
                else if(strstr(buf,"+X")!=NULL||s[0]=='X') coe=1;
                index=findexp(exp);
            }
            printf("%d %d %d\n",coe,exp,index);
            ec[index].coe+=coe;
        }
        sort(ec,ec+pec);
        int i;
        for(i=0;i<pec;i++)
            printf("exp:%d coe:%d\n",ec[i].exp,ec[i].coe);
        print();
    }
    return 0;
}
