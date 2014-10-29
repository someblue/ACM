#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2005;
int n, c, t1, t2, a[N], dp[N];

int main()
{
	while (~scanf("%d%d%d%d", &n, &c, &t1, &t2))
	{
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d", &a[i]);
			a[i+n] = a[i]+c;
		}
		int ans = 1000000000;
		for (int o = 1; o <= n; o ++)
		{
			dp[o-1] = 0;
			for (int i = 0; i < n; i ++)
			{
				int t3 = lower_bound(a+o, a+i+o, a[i+o]-t1)-a, t4 = lower_bound(a+o, a+i+o, a[i+o]-t2)-a;
				dp[i+o] = min(dp[t3-1]+t1, dp[t4-1]+t2);
			}
			ans = min(dp[o+n-1], ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}
