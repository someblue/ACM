#include <cstdio>
#include <cstring>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int N = 30010;
int r,n,m;
struct _matrix
{
    int mat[3][3];
    _matrix operator * (const _matrix &b) const {
        _matrix res;
        for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
        {
            int sum=0;
            for(int k=0;k<2;++k)    sum+=mat[i][k]*b.mat[k][j];
            res.mat[i][j]=sum%r;
        }
        return res;
    }
    void clear()    {memset(mat,0,sizeof(mat));for(int i=0;i<2;++i) mat[i][i]=1;}
    void in()   {scanf("%d%d%d%d",&mat[0][0],&mat[0][1],&mat[1][0],&mat[1][1]);}
    void out()  {printf("%d %d\n%d %d\n",mat[0][0],mat[0][1],mat[1][0],mat[1][1]);}
};
_matrix res[4*N];
void up(int rt)
{
    res[rt] = res[rt<<1] * res[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        res[rt].in();
        return;
    }
    int mid = (l+r)>>1;
    build(lson);
    build(rson);
    up(rt);
}
_matrix query(int L,int R,int l,int r,int rt)
{
    if(L<=l && r<=R)    return res[rt];
    int mid = (l+r)>>1;
    _matrix ans;
    ans.clear();
    if(L<=mid)  ans=ans*query(L,R,lson);
    if(R>mid)   ans=ans*query(L,R,rson);
    return ans;
}
bool fir2=1;
void run()
{
    if(fir2) fir2=0;
    else puts("");
    build(1,n,1);
    int l,r;
    bool fir=1;
    while(m--)
    {
        if(fir) fir=0;
        else puts("");
        scanf("%d%d",&l,&r);
        query(l,r,1,n,1).out();
    }
}
int main()
{
    freopen("case.txt","r",stdin);
    while(scanf("%d%d%d",&r,&n,&m)!=EOF)
        run();
    return 0;
}

/*
0 1
0 0

1 2
0 0

0 1
0 0

0 2
0 0

2 1
1 2

0 2
0 1

0 1
0 2

0 0
0 2

0 0
0 1

1 0
0 2
*/
