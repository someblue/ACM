#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define N 100005
using namespace std;
typedef pair<int,int> pii;

int disc[N*2],kd;
struct _rec{
    char c;
    int l,r;
};
_rec rec[N];
pii seg[N];int segcnt;

struct _bit{
    int sum[N*2];
    int up;
    void init(int x)
    {
        up=x;
        memset(sum,0,sizeof(sum));
    }
    int lowbit(int x)
    {
        return x& -x;
    }
    void add(int x)
    {
        while(x<=up){
//            cout<<"bit add"<<endl;
            ++sum[x];
            x+=lowbit(x);
        }
    }
    void sub(int x)
    {
        while(x<=up){
//            cout<<"bit sub"<<endl;
            --sum[x];
            x+=lowbit(x);
        }
    }
    int get(int x)
    {
        int res=0;
        while(x>0){
//            cout<<"bit get"<<endl;
            res+=sum[x];
            x-=lowbit(x);
        }
        return res;
    }
    int getall()
    {
        return get(up);
    }
};
_bit bl,br;

int bs(int x)
{
    int l=1,r=kd+1,mid;
    while(l<r)
    {
        mid=(l+r)/2;
//        cout<<l<<' '<<mid<<' '<<r<<endl;
        if(x==disc[mid])    return mid;
        if(x<disc[mid])     r=mid;
        else                l=mid+1;
    }
    return l;
}

inline char readChar()
{
    char c;
    c=getchar();
    while(!isalpha(c))  c=getchar();
    return c;
}

int main()
{
    freopen("in.txt","r",stdin);
    int i;
    int n,l,r;
    char c;
    kd=0;segcnt=0;
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
//        scanf("%c%c",&c,&c);
        c=readChar();
        rec[i].c=c;
        if(c=='C')
        {
            scanf("%d",&rec[i].l);
            disc[++kd]=rec[i].l;
        }
        else
        {
            scanf("%d%d",&rec[i].l,&rec[i].r);
            disc[++kd]=rec[i].l;
            disc[++kd]=rec[i].r;
        }
    }
//    cout<<"read finish"<<endl;
    sort(disc+1,disc+1+kd);
    int kd2=1;
    for(i=1;i<=kd;++i)
        if(disc[i]!=disc[kd2])
            disc[++kd2]=disc[i];
    kd=kd2;
//    cout<<"discrete finish"<<endl;
    bl.init(kd);
    br.init(kd);
    int delcnt=0;
    for(i=0;i<n;i++)
    {
        if(rec[i].c=='C')
        {
            l=seg[rec[i].l].first;
            r=seg[rec[i].l].second;
            bl.sub(l);
            br.sub(r);
            ++delcnt;
        }
        else if(rec[i].c=='D')
        {
            l=bs(rec[i].l);
            r=bs(rec[i].r);
            bl.add(l);
            br.add(r);
            ++segcnt;
            seg[segcnt].first = l;
            seg[segcnt].second = r;
        }
        else
        {
            l=bs(rec[i].l);
            r=bs(rec[i].r);
            printf("%d\n",segcnt-delcnt-br.get(l-1)-(bl.getall()-bl.get(r)));
        }
    }
//    cout<<"kd="<<kd<<' '<<bl.up<<endl;
//    for(i=0;i<=segcnt;i++)
//        cout<<i<<": "<<seg[i].first<<' '<<seg[i].second<<endl;
//    for(i=1;i<=kd;i++)
//        cout<<bl.get(i)<<' ';
//    cout<<endl;
//    for(i=1;i<=kd;i++)
//        cout<<br.get(i)<<' ';
    return 0;
}
