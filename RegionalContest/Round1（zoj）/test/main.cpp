#include <bits/stdc++.h>

using namespace std;
int res[100];
int tmp1[100],tmp2[100];
bool cmp(int *a,int *b,int sz)
{
    for(int i=sz-1;i>=0;i--)
        if(a[i]<b[i]) return 1;
        else if(a[i]>b[i]) return 0;
    return 0;
}
void cpy(int *a,int *b,int l,int r)
{
    for(int i=l;i<=r;i++)
        a[i] = b[i];
}
void blue(int l,int r)
{
    int sz = r-l+1;
    bool fir = 1;
    cpy(tmp2,res,l,r);
    for(int i=l;i<=r;i++) printf("%d",tmp2[i]); puts("");
    for(int i=1;i<sz;i++)
    {
        int lmn,rmn;
        lmn = rmn = 100;
        for(int j=l;j<l+i;j++)
            if(lmn > tmp2[j])
                lmn = tmp2[j];
        for(int j=l+i;j<=r;j++)
            if(rmn > tmp2[j])
                rmn = tmp2[j];
        for(int j=l;j<l+i;j++)
            tmp1[j] = lmn;
        for(int j=l+i;j<=r;j++)
            tmp1[j] = rmn;
        cout<<lmn<<' '<<rmn<<endl;
        if(fir || cmp(res+l,tmp1+r,sz))
        {
            if(fir) fir = 0;
            cpy(res,tmp1,l,r);
        }
    }
}
int main()
{
    int l,r;
    int n;
    while(true)
    {
        cin>>n;
        for(int i=0;i<n;i++) scanf("%d",&res[i]);
        cin>>l>>r;
        blue(l,r);
        for(int i=0;i<n;i++) printf("%d",res[i]); puts("");
    }
    return 0;
}
