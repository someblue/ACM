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

void run()
{
}

int main()
{
    int a1,a2,a3,b1,b2,b3,n;
    cin>>a1>>a2>>a3>>b1>>b2>>b3>>n;
    int a,b;
    a=(a1+a2+a3)/5;
    if((a1+a2+a3)%5)    a++;
    b=(b1+b2+b3)/10;
    if((b1+b2+b3)%10)   b++;
    if(a+b<=n)  cout<<"YES"<<endl;
    else        cout<<"NO"<<endl;
    return 0;
}
