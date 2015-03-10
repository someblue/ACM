#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>

using namespace std;

const int N = 500005;
const int INF = 0x3f3f3f3f;
int a[N], b[N];
multiset<int> se, se2;
char s[20];
int n, m;

int myabs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		se.clear();
		se2.clear();
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d", &a[i]);
			se.insert(a[i]);
			b[i] = a[i];
		}
		int mi = INF;
		for (int i = 2; i <= n; i ++)
		{
			se2.insert(myabs(a[i]-a[i-1]));
		}
		for (multiset<int>::iterator i = se.begin(); ;)
		{
			multiset<int>::iterator j = i;
			i ++;
			if (i == se.end()) break;
			mi = min(mi, myabs((*i)-(*j)));
		}
		while (m --)
		{
			scanf("%s", s);
			if (s[0] == 'I')
			{
				int x, y;
				scanf("%d%d", &x, &y);
				multiset<int>::iterator it = se.lower_bound(y);
				mi = min(mi, myabs((*it)-y));
				if (it != se.begin())
				{
					it --;
					mi = min(mi, myabs((*it)-y));
				}
				se.insert(y);
				if (x != n)
				{
					it = se2.lower_bound(myabs(b[x]-a[x+1]));
					se2.erase(it);
					se2.insert(myabs(a[x+1]-y));
				}
				se2.insert(myabs(y-b[x]));
				b[x] = y;
			}
			else if (s[1] == 'i') printf("%d\n", mi);
			else
			{
				multiset<int>::iterator it = se2.end();
				it --;
				printf("%d\n", *it);
			}
		}
	}
	return 0;
}

