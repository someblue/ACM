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
const int N = 100;
int a,b;

int main()
{
//    freopen("case.txt","r",stdin);
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int day;
        for(day=1;;day++)
        {
            a--;
            if(day%b==0)    a++;
            if(!a)  break;
        }
        printf("%d\n",day);
    }
    return 0;
}
