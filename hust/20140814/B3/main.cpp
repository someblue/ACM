#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int N = 30010;
int r,n,m,M;
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
    _matrix operator *= (const _matrix &b)  {
        return *this = (*this) * b;
    }
    void clear()    {memset(mat,0,sizeof(mat));for(int i=0;i<2;++i) mat[i][i]=1;}
    void in()   {scanf("%d%d%d%d",&mat[0][0],&mat[0][1],&mat[1][0],&mat[1][1]);}
    void out()  {printf("%d %d\n%d %d\n",mat[0][0],mat[0][1],mat[1][0],mat[1][1]);}
};
_matrix res[4*N];
void build(int x)
{
    _matrix tmp;
    tmp.in();
    for(x+=M;x;x>>=1)   res[x] *= tmp;
}
vector<int> vi;
_matrix query(int x,int y)
{
    _matrix ans;
    ans.clear();
    vi.clear();
    int l=x+M-1,r=y+M+1;
    for(x=l,y=r;x^y^1;x>>=1,y>>=1)
        if(~x&1) ans*=res[x^1];
    for(x=l,y=r;x^y^1;x>>=1,y>>=1)
        if(y&1)
            vi.push_back(y^1);
    for(int i=vi.size()-1;i>=0;--i)
        ans *= res[vi[i]];
    return ans;
}
bool fir2=1;
void run()
{
    if(fir2) fir2=0;
    else puts("");
    for(M=1;M<=n;M+=M);
    for(int i=0;i<=M+n;++i) res[i].clear();
    for(int i=1;i<=n;++i)
        build(i);
    int l,r;
    bool fir=1;
    while(m--)
    {
        if(fir) fir=0;
        else puts("");
        scanf("%d%d",&l,&r);
        query(l,r).out();
    }
}
int main()
{
    while(scanf("%d%d%d",&r,&n,&m)!=EOF)
        run();
    return 0;
}
