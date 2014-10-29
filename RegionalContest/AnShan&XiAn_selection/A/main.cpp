#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;
typedef pair<Point, Point> Node;
#define x first
#define y second

const int N = 555;
Point pt[N];
map<Point, int> cnt;
map<Node, int> cnt2;
Point operator + (const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator - (const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }

inline int Count(const int x) {
	return x * (x - 1) >> 1;
}

inline Point Fix(Point a) {
	int g = __gcd(abs(a.x), abs(a.y));
	a.x /= g;
	a.y /= g;
	if (a.x < 0) {
		a.x = -a.x;
		a.y = -a.y;
	}
	return a;
}

int main() {
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; ++i) {
			cin >> pt[i].x >> pt[i].y;
		}
		cnt.clear();
		cnt2.clear();
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				++cnt[pt[i] + pt[j]];
				++cnt2[Node(pt[i] + pt[j], Fix(pt[i] - pt[j]))];
			}
		}
		int answer = 0;
		for (map<Point, int>::iterator mi = cnt.begin(); mi != cnt.end(); ++mi) {
			answer += Count(mi->y);
		}
		for (map<Node, int>::iterator mi = cnt2.begin(); mi != cnt2.end(); ++mi) {
			answer -= Count(mi->y);
		}
		cout << answer << endl;
	}
	return 0;
}
