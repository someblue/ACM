//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
using namespace std;
const int N = 500010;
const int INF = 1e9;

int n, m, a[N], b[N], mn;
multiset<int> se, se2;
char com[20];

inline int myabs(int x) {
	return x>0? x: -x;
}

int main() {
	int idx, x;
	while(~scanf("%d%d", &n, &m)) {
		se.clear();
		se2.clear();
		mn = INF;
		for(int i=1; i<=n; i++) {
			scanf("%d", a+i);
			se.insert(a[i]);
			b[i] = a[i];
		}
		for(int i=2; i<=n; i++)
			se2.insert(myabs(a[i]-a[i-1]));
		for(multiset<int>::iterator it = se.begin(); ; ) {
			multiset<int>::iterator it2 = it;
			it++;
			if(it == se.end())
				break;
			mn = min(mn, myabs((*it) - (*it2)));
		}
		//show_se();
		//cout << "Min: " << mn << endl;
		while(m--) {
			scanf("%s", com);
			if(com[0] == 'I') {
				scanf("%d%d", &idx, &x);

				multiset<int>::iterator it = se.lower_bound(x);
				mn = min(mn, myabs((*it) - x));
				if(it!=se.begin()) {
					it--;
					mn = min(mn, myabs(x - (*it)));
				}
				se.insert(x);

				if(idx!=n) {
					it = se2.lower_bound(myabs(b[idx] - a[idx+1]));
					//se2.erase(myabs(b[i] - a[i+1]));
					se2.erase(it);
					se2.insert(myabs(x - a[idx+1]));
				}
				se2.insert(myabs(b[idx] - x));
				b[idx] = x;

				//show_se();
			} else if(com[1] == 'i') {
				printf("%d\n", mn);
			} else {
				multiset<int>::iterator it = se2.end();
				it--;
				printf("%d\b", *it);
			}
		}
	}
	return 0;
}
