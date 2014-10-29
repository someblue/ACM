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
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int N = 1000;
int L[N];

void init()
{
    L[0]=2;
    L[1]=1;
    for(int i=2;i<N;++i)
        L[i]=L[i-1]+L[i-2];
}

void test()
{
    for(int i=0;i<100;++i)
    {
        if(i%10==0) cout<<endl;
        cout<<L[i]<<' ';
    }
}

void run()
{

}

int main()
{
    init();
    test();
//    freopen("case.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
