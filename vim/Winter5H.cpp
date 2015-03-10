#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 130;
ll a[N], x;
int n;

int main() {
	while(~scanf("%d",&n)) {
		if(n>=N) {
			for(int i=0; i<n; i++)
				scanf("%d", &x);
			puts("Yes");
			continue;
		}
		for(int i=0; i<n; i++) {
			scanf("%I64d", a+i);
		}
		bool ans = 0;
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				for(int k=j+1; k<n; k++) {
					for(int l=k+1; l<n; l++) {
						if((a[i] ^ a[j] ^ a[k] ^ a[l]) == 0) {
							printf("find ans: %d, %d, %d, %d\n", i,j,k,l);
							ans = 1;
							goto bk;
						}
					}
				}
			}
		}
bk:
		if(ans) puts("Yes");
		else puts("No");
	}
	return 0;
}

