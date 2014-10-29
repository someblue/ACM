#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <map>
#define VI vector<int>
#define N 1010
using namespace std;
typedef long long ll;

char s[N];

int findleft(char key,int l)
{
    int i;
    for(i=l+1;;i++)
        if(s[i]==key) return i;
}
int findright(char key,int r)
{
    int i;
    for(i=r-1;;i--)
        if(s[i]==key) return i;
}

void dfs(int l,int r,int &pop)
{
    //cout<<'.'<<endl;
    while(l<r && s[l]==s[r]) {l++;r--;}
    if(l>=r) return;
    int f,p1,p2,p3;
    int ll=l,rr=r;
    p1=p2=p3=pop;

    l=ll;r=rr;
    f=findright(s[l],r);
    p1= pop+r-f;
    l++;r=f-1;
    dfs(l,r,p1);

    l=ll;r=rr;
    f=findleft(s[r],l);
    p2= pop+f-l;
    l=f+1;r--;
    dfs(l,r,p2);

    l=ll;r=rr;
    l++;r--;p3+=2;
    dfs(l,r,p3);

    pop=min( min(p1,p2),p3 );
    //printf("dfs(%d,%d): p1=%d p2=%d p3=%d pop=%d\n",ll,rr,p1,p2,p3,pop);
}

void run()
{
    int pop=0;
    gets(s);
    dfs(0,strlen(s)-1,pop);
    //cout<<"pop: "<<pop<<' ';
    printf("%s\n",(pop&1)?"Second":"First");
}

int main()
{
    //freopen("in","r",stdin);
    run();
    return 0;
}

/*
WA
*/
