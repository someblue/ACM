/*
* this code is made by WJMKQDM
* Problem: 1157
* Verdict: Accepted
* Submission Date: 2014-07-23 02:25:57
* Time: 2120MS
* Memory: 8692KB
*/
#include <bits/stdc++.h>
using namespace std;
 
const int N = 111111;
const int BRUTE_FORCE = 1 << 8;
struct Node {
    int op; // 0: insert  1: delete  2: query
    int x, y, id;
    Node() {}
    Node(int op, int x, int y) : op(op), x(x), y(y) {}
} node[N], temp[N];
int x[N], y[N], X[N << 1], cx, answer[N];
bool out[N];
 
inline int GetPos(const int a) { return lower_bound(X, X + cx, a) - X + 1; }
inline int Lowbit(const int a) { return a & -a; }
struct BIT {
    int a[N << 1], n, isCleaning;
    stack<int> p, c;
    void Init(int _n) {
        n = _n + 2;
        for (int i = 0; i < n; ++i) {
            a[i] = 0;
        }
        while (!p.empty()) {
            p.pop();
        }
        while (!c.empty()) {
            c.pop();
        }
        isCleaning = 0;
    }
    void Clear() {
        isCleaning = 1;
        while (!p.empty()) {
            Add(p.top(), -c.top());
            p.pop();
            c.pop();
        }
        isCleaning = 0;
    }
    void Add(int x, int d) {
        if (!isCleaning) {
            p.push(x);
            c.push(d);
        }
        for ( ; x < n; x += Lowbit(x)) {
            a[x] += d;
        }
    }
    int Sum(int x) {
        int sum = 0;
        for ( ; x > 0; x -= Lowbit(x)) {
            sum += a[x];
        }
        return sum;
    }
} bit;
 
inline bool Cmp(const Node &a, const Node &b) { return a.x < b.x; }
void Solve(int l, int r) {
    if (l + BRUTE_FORCE >= r) {
        for (int i = l; i < r; ++i) {
            if (node[i].op == 2) {
                for (int j = l; j < i; ++j) {
                    if (node[j].op == 2) {
                        continue;
                    }
                    if (node[j].x <= node[i].x && node[i].y <= node[j].y) {
                        if (node[j].op == 0) {
                            ++answer[node[i].id];
                        } else {
                            --answer[node[i].id];
                        }
                    }
                }
            }
        }
        sort(node + l, node + r, Cmp);
        return ;
    }
    //if (l + 1 >= r) { return ; }
    int m = l + r >> 1;
    Solve(l, m);
    Solve(m, r);
    for (int i = l; i < r; ++i) {
        temp[i] = node[i];
    }
    int a = l, b = m, tt = l, cnt = 0;
    while (a < m || b < r) {
        if (b >= r || a < m && temp[a].x <= temp[b].x) { // a
            if (temp[a].op == 2) {
                node[tt++] = temp[a++];
                continue;
            }
            int p = GetPos(temp[a].y);
            if (temp[a].op) {
                bit.Add(p, -1);
                --cnt;
            } else {
                bit.Add(p, 1);
                ++cnt;
            }
            node[tt++] = temp[a++];
        } else { // b
            if (temp[b].op == 2) {
                int p = GetPos(temp[b].y);
                answer[temp[b].id] += cnt - bit.Sum(p - 1);
            }
            node[tt++] = temp[b++];
        }
    }
    bit.Clear();
}
 
int Run() {
    int n;
    while (~scanf("%d", &n)) {
        int c = 0, a;
        char op[3];
        cx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", op);
            node[i].id = i;
            out[i] = answer[i] = 0;
            if (*op == 'D') {
                ++c;
                scanf("%d%d", x + c, y + c);
                node[i] = Node(0, x[c], y[c]);
                X[cx++] = x[c];
                X[cx++] = y[c];
            } else if (*op == 'C') {
                scanf("%d", &a);
                node[i] = Node(1, x[a], y[a]);
            } else {
                out[i] = 1;
                node[i].op = 2;
                scanf("%d%d", &node[i].x, &node[i].y);
                X[cx++] = node[i].x;
                X[cx++] = node[i].y;
            }
        }
        sort(X, X + cx);
        cx = unique(X, X + cx) - X;
        bit.Init(cx);
        Solve(0, n);
        for (int i = 0; i < n; ++i) {
            if (out[i]) {
                printf("%d\n", answer[i]);
            }
        }
    }
    return 0;
}
 
int main() {
    //freopen("in", "r", stdin);
    //ios::sync_with_stdio(0);
    return Run();
}