#include <bits/stdc++.h>
using namespace std;
const int N = 310;

int m,t,r;
int w[N];
int times[N];

void run()
{
    for(int i=0; i<m; i++)
        scanf("%d", w+i);
    if(t < r)
    {
        cout << "-1" << endl;
        return;
    }
    memset(times,0,sizeof(times));
    int ans = 0;
    for(int i=0; i<m; i++)
    {
        int d = r - times[w[i]];
        ans += d;
        for(int l=w[i]-d; l<w[i]; l++)
        {
            for(int j=l+1; j<=l+t; j++)
                if(j>=1 && j <N)
                    times[j]++;
        }
//        for(int j=1; j<=10; j++)
//            cout << times[j] << ' ';
//        cout << endl;
    }
    cout << ans << endl;
}

int main()
{
    while(cin >> m >> t >> r)
        run();
    return 0;
}
