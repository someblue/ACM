#include <cstdio>
#include <cstring>
#include <cctype>
inline int getc() {
    static const int L = 1 << 15;
    static char buf[L] , *S = buf , *T = buf;
    if (S == T) {
        T = (S = buf) + fread(buf , 1 , L , stdin);
        if (S == T)
            return EOF;
    }
    return *S++;
}
inline int getint() {
    int c;
    while(!isdigit(c = getc()));
    int tmp = c - '0';
    while(isdigit(c = getc()))
        tmp = (tmp << 3) + (tmp << 1) + c - '0';
    return tmp;
}
typedef long long LL;
int mod;
struct Mark {
    int u , v;
    Mark(int _u = -1 , int _v = -1):u(_u),v(_v){}
    bool operator == (const Mark &b) const {
        return u == b.u && v == b.v;
    }
    bool operator != (const Mark &b) const {
        return u != b.u || v != b.v;
    }
    void operator += (const Mark &b) {
        if (u == -1 && v == -1)
            *this = b;
        else {
            u = (LL)u * b.u % mod;
            v = ((LL)v * b.u + b.v) % mod;
        }
    }
}null(-1 , -1);
void inc(int &a , int b , int c) {
    a = ((LL)b + c >= mod) ? b - mod + c : b + c;
}
#define N ((131072 << 1) + 10)
int sav[100010];
struct SegmentTree {
    int M , sum[N] , size[N];
    Mark c[N];
    void build(int _size) {
        for(M = 1 ; M < (_size + 2) ; M <<= 1);
        int i;
        for(i = 0 ; i < M ; ++i)
            sum[M + i] = sav[i] , size[M + i] = 1;
        for(i = M - 1 ; i >= 1 ; --i) {
            inc(sum[i] , sum[i << 1] , sum[(i << 1) | 1]);
            size[i] = size[i << 1] + size[(i << 1) | 1];
        }
    }
    int stack[25] , top;
    void make_Mark(int x , Mark _c) {
        c[x] += _c;
        sum[x] = ((LL)sum[x] * _c.u + (LL)_c.v * size[x]) % mod;
    }
    void pushdown(int x) {
        if (c[x] != null && x < M) {
            if (x << 1)
                make_Mark(x << 1 , c[x]);
            if ((x << 1) | 1)
                make_Mark((x << 1) | 1 , c[x]);
            c[x] = null;
        }
    }
    void update_path(int x) {
        top = 0;
        for(; x ; x >>= 1)
            stack[++top] = x;
        while(top--)
            pushdown(stack[top]);
    }
    int query(int tl , int tr) {
        int insl = 0 , insr = 0 , res = 0;
        for(tl = tl + M - 1 , tr = tr + M + 1 ; tl ^ tr ^ 1 ; tl >>= 1 , tr >>= 1) {
            if (~tl & 1) {
                if (!insl)
                    update_path(insl = tl ^ 1);
                inc(res , res , sum[tl ^ 1]);
            }
            if (tr & 1) {
                if (!insr)
                    update_path(insr = tr ^ 1);
                inc(res  ,res , sum[tr ^ 1]);
            }
        }
        return res;
    }
    void modify(int tl , int tr , Mark _c) {
        int insl = 0 , insr = 0;
        for(tl = tl + M - 1 , tr = tr + M + 1 ; tl ^ tr ^ 1 ; tl >>= 1 , tr >>= 1) {
            if (~tl & 1) {
                if (!insl)
                    update_path(insl = tl ^ 1);
                make_Mark(tl ^ 1 , _c);
            }
            if (tr & 1) {
                if (!insr)
                    update_path(insr = tr ^ 1);
                make_Mark(tr ^ 1 , _c);
            }
        }
        for(insl = insl >> 1 ; insl ; insl >>= 1)
            inc(sum[insl] , sum[insl << 1] , sum[(insl << 1) | 1]);
        for(insr = insr >> 1 ; insr ; insr >>= 1)
            inc(sum[insr] , sum[insr << 1] , sum[(insr << 1) | 1]);
    }
}ZKW;
int n;
int main() {
    n = getint();
    mod = getint();
    int i;
    for(i = 1 ; i <= n ; ++i)
        sav[i] = getint() , sav[i] %= mod;
    ZKW.build(n);
    int ask = getint();
    int sign , a , b , x;
    while(ask--) {
        sign = getint();
        a = getint();
        b = getint();
        if (sign == 1) {
            x = getint();
            ZKW.modify(a , b , Mark(x % mod, 0));
        }
        else if (sign == 2) {
            x = getint();
            ZKW.modify(a , b , Mark(1 , x % mod));
        }
        else
            printf("%d\n" , ZKW.query(a , b));
    }
    return 0;
}
