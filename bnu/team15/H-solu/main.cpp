#include <bits/stdc++.h>
using namespace std;

typedef double DB;
typedef pair<DB, DB> Point;
#define x first
#define y second
const DB EPS = 1e-8;
const DB R3D2 = sqrt(3) / 2;
const Point O(0, 0);
inline int Sgn(const DB &a) { return (a > EPS) - (a < -EPS); }

istream &operator >> (istream &in, Point &a) { return in >> a.x >> a.y; }
ostream &operator << (ostream &out, const Point &a) { return out << a.x << ' ' << a.y; }
Point operator + (const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator - (const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator * (const Point &a, const DB &p) { return Point(a.x * p, a.y * p); }
Point operator / (const Point &a, const DB &p) { return Point(a.x / p, a.y / p); }
bool operator == (const Point &a, const Point &b) { return Sgn(a.x - b.x) == 0 && Sgn(a.y - b.y) == 0; }
inline DB Cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
inline DB Dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
inline DB Length(const Point &a) { return hypot(a.x, a.y); }
inline Point VecUnit(const Point &a) { return a / Length(a); }
inline Point Normal(const Point &a) { return Point(-a.y, a.x); }

struct Line {
	Point s, t;
	Line() {}
	Line(const Point &s, const Point &t) : s(s), t(t) {}
	Point Vec() const {
		return t - s;
	}
	Point GetPoint(const DB &p) const {
		return s + Vec() * p;
	}
} ;
inline Point LLint(const Line &a, const Line &b) { return a.GetPoint(Cross(b.Vec(), a.s - b.s) / Cross(a.Vec(), b.Vec())); }
inline bool OnSeg(const Point &p, const Point &a, const Point &b) { return Sgn(Cross(a - p, b - p)) == 0 && Sgn(Dot(a - p, b - p)) <= 0; }
inline DB GetLineDist(const Point &p, const Point &a, const Point &b) { return fabs(Cross(p - a, p - b) / Length(a - b)); }

DB GetDist(const Point &p, const Point &a, const Point &b) {
	if (Sgn(Dot(p - a, b - a)) <= 0) {
		return Length(p - a);
	}
	if (Sgn(Dot(p - b, a - b)) <= 0) {
		return Length(p - b);
	}
	return GetLineDist(p, a, b);
}

const int HEX = 6;
const DB HexX[] = { 0.5, 1, 0.5, -0.5, -1, -0.5 };
const DB HexY[] = { -R3D2, 0, R3D2, R3D2, 0, -R3D2 };

Point Hex[HEX + 1];

void BuildHex(const DB &s) {
	for (int i = 0; i < HEX; ++i) {
		Hex[i] = Point(HexX[i] * s, HexY[i] * s);
	}
	Hex[HEX] = Hex[0];
}

Point B[2];
DB s, r;
int t;

Point FindCrash() {
	DB dist = DBL_MAX, td;
	Point ip, temp;
	for (int i = 0; i < HEX; ++i) {
		if (Sgn(Cross(B[1] - B[0], Hex[i + 1] - Hex[i])) == 0) {
			continue;
		}
		temp = LLint(Line(Hex[i], Hex[i + 1]), Line(B[0], B[1]));
		if (OnSeg(temp, Hex[i], Hex[i + 1])) {
			if (Sgn(Dot(temp - B[0], B[1] - B[0])) > 0) {
				if (dist > (td = Length(temp - B[0]))) {
					dist = td;
					ip = temp;
				}
			}
		}
	}
	return ip;
}

bool ToHole() {
	B[1] = FindCrash();
	//cout << "crash point " << B[1] << endl; cout << r << ' ' << GetDist(O, B[0], B[1]) << endl;
	return Sgn(GetDist(O, B[0], B[1]) - r) <= 0;
}

void Reflect(const Point *const B, Point *const C, const Point &a, const Point &b) {
	Point v = VecUnit(Normal(a - b)), ip = LLint(Line(a, b), Line(B[0], B[0] + v));
	Point Bp = B[0] + v * (Length(ip - B[0]) * 2);
	//cout << "BP " << Bp << ' ' << (Length(ip - B[0]) * 2) << ' ' << v << endl;
	C[0] = B[1];
	C[1] = C[0] + VecUnit(B[1] - Bp);
}

int GetReflect() {
	Point C[2];
	int id, c = 0;
	for (int i = 0; i < HEX; ++i) {
		if (OnSeg(B[1], Hex[i], Hex[i + 1])) {
			++c;
			id = i;
		}
	}
	if (c > 1) {
		swap(B[0], B[1]);
	} else {
		Reflect(B, C, Hex[id], Hex[id + 1]);
		//cout << B[0] << ' ' << B[1] << ' ' << C[0] << ' ' << C[1] << ' ' << Hex[id] << ' ' << Hex[id + 1] << ' ' << id << endl;
		B[0] = C[0];
		B[1] = C[1];
	}
	return c;
}

void Solve() {
	BuildHex(s);
	//for (int i = 0; i < HEX; ++i) { cout << Hex[i] << endl; }
	while (t > 0 && ToHole() == 0) {
		int c = GetReflect();
		//cout << "hit " << c << endl;
		t -= c;
	}
}

int main() {
	//freopen("in_h", "r", stdin);
	ios::sync_with_stdio(0);
	cout << setiosflags(ios::fixed) << setprecision(5);
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		cin >> s >> B[0] >> B[1] >> r >> t;
		Solve();
		cout << "Case " << cas << ": ";
		if (t <= 0) {
			cout << "Stops" << endl;
		} else {
			cout << t << endl;
		}
	}
	return 0;
}
