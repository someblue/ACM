#include <bits/stdc++.h>
#define N 200005
using namespace std;

struct suffix_array{
    char s[N];
    int sa[N],t[N],t2[N],c[N],n;
    int rk[N],height[N];
    void build(int m=256)//先输入s数组，再build
    {
        n=strlen(s);
        int i,*x=t,*y=t2;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[i]=s[i]]++;
        for(i=1;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
        for(int k=1;k<=n;k<<=1)
        {
            int p=0;
            for(i=n-k;i<n;i++) y[p++]=i;
            for(i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;

            for(i=0;i<m;i++) c[i]=0;
            for(i=0;i<n;i++) c[x[y[i]]]++;
            for(i=0;i<m;i++) c[i]+=c[i-1];
            for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];

            swap(x,y);
            p=1;x[sa[0]]=0;
            for(i=1;i<n;i++)
                x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
            if(p>=n) break;
            m=p;
        }
        int j,k=0;
        for(i=0;i<n;i++) rk[sa[i]]=i;
        for(i=0;i<n;i++)
        {
            if(k)k--;
            j=sa[rk[i]-1];
            while(s[i+k]==s[j+k]) k++;
            height[rk[i]]=k;
        }
    }
};

void text()
{
    cout<<(int)'$'<<endl;
    cout<<(int)'a'<<endl;
    cout<<(int)'A'<<endl;
}

int main()
{
    text();
    cout << "Hello world!" << endl;
    return 0;
}
