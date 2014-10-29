struct SegmentTree
{
    // fix
    int N;
    vector<int> height;
    vector<int> len;
    int M;
    void up(int x)
    {
        while (x > 1)
        {
            inlineup(x >> 1);
            x >>= 1;
        }
    }
    void down(int x)
    {
        for (int i = height[1]; i >= 1; --i) inlinedown(x >> i);
    }

    // prob spec
    vector<long long> delta;
    vector<long long> sum;

    SegmentTree(int n)
    {
        // fix
        N = n;
        M = 1;
        while (M < N + 2) M <<= 1;
        height.resize(M + M, 0);
        len.resize(M + M, 0);
        for (int i = M; i < M + M; ++i) len[i] = 1;
        for (int i = M - 1; i >= 1; --i)
        {
            len[i] = len[i + i] << 1;
            height[i] = height[i + i] + 1;
        }

        // problem spec
        delta.resize(M + M, 0);
        sum.resize(M + M, 0);
    }

    // init the segment by initial value, important for speed up
    void init(vector<int> & ps, vector<int> & vs)
    {
        for (int i = 0; i < ps.size(); ++i)
        {
            int p = ps[i] + M;
            int v = vs[i];
            // prob spec
            delta[p] = v;
            sum[p] = v;
        }
        for (int i = M - 1; i >= 1; --i) inlineup(i);
    }

    inline void inlinedown(int f)
    {
        int ls = f + f;
        int rs = f + f + 1;

        // prob spec
        delta[ls] += delta[f];
        delta[rs] += delta[f];
        sum[ls] += delta[f] * len[ls];
        sum[rs] += delta[f] * len[rs];
        delta[f] = 0;
    }

    inline void inlineup(int f)
    {
        int ls = f + f;
        int rs = f + f + 1;

        // prob spec
        sum[f] = sum[ls] + sum[rs] + delta[f] * len[f];
    }

    void update(int l, int r, int d)
    {
        if (l > r) return;
        l += M - 1;
        r += M + 1;
        int ll = l;
        int rr = r;
        //down(ll); down(rr);
        while (true)
        {
            if ((l ^ r) == 1) break;
            if ((l & 1) == 0)
            {
                // prob spec
                int n = l ^ 1;
                delta[n] += d;
                sum[n] += (long long) d * len[n];
            }
            if ((r & 1) == 1)
            {
                // prob spec
                int n = r ^ 1;
                delta[n] += d;
                sum[n] += (long long) d * len[n];
            }
            l >>= 1;
            r >>= 1;
        }
        up(ll);
        up(rr);
    }

    long long query(int l, int r)
    {
        l += M - 1;
        r += M + 1;
        down(l);
        down(r);

        long long ret = 0;
        while (true)
        {
            if ((l ^ r) == 1) break;
            if ((l & 1) == 0)
            {
                // prob spec
                int n = l ^ 1;
                ret += sum[n];
            }
            if ((r & 1) == 1)
            {
                // prob spec
                int n = r ^ 1;
                ret += sum[n];
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
};
