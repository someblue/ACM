#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100;
int cas = 1;
double r,x1,yy1,x2,y2;
void run()
{
    double dis = sqrt((x1-x2)*(x1-x2) + (yy1-y2)*(yy1-y2));
    dis /= 2*r;
    cout << (int) ceil(dis) << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(cin>>r>>x1>>yy1>>x2>>y2)
        run();
    return 0;
}
