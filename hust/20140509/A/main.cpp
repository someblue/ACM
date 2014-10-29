#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#define N
using namespace std;

int get()
{
    int res=0;
    char c;
    while(1)
    {
        c=getchar();
        if(c!='|') return res;
        res++;
    }
    return res;
}
void print(int a,int b,int c)
{
    int i;
    for(i=1;i<=a;i++)   cout<<"|";
    cout<<'+';
    for(i=1;i<=b;i++)   cout<<"|";
    cout<<'=';
    for(i=1;i<=c;i++)   cout<<"|";
    cout<<endl;
}
void run()
{
    int a,b,c;
//    while(1)
    {
        a=get();b=get();c=get();//getchar();
//        cout<<a<<' '<<b<<' '<<c<<endl;
        if(a+b==c)  print(a,b,c);
        else if(c>1&&a+1+b==c-1) print(a+1,b,c-1);
        else if(a-1+b==c+1&&(a>1||b>1))
        {
            if(a>1) print(a-1,b,c+1);
            else if(b>1) print(a,b-1,c+1);
        }
        else printf("Impossible\n");
    }
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
