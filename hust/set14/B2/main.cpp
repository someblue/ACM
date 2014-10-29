#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;
const int N = 1000005;

char s[N],s2[N],s3[N];
int f[N];
int l;
int minidx,minnum;
int maxidx,maxnum;

int MinimumRepresentation(char *s, int l)
{
    int i = 0, j = 1, k = 0, t;
    while(i < l && j < l && k < l) {
        t = s[(i + k) >= l ? i + k - l : i + k] - s[(j + k) >= l ? j + k - l : j + k];
        if(!t) k++;
        else{
            if(t > 0) i = i + k + 1;
            else j = j + k + 1;
            if(i == j) ++ j;
            k = 0;
        }
    }
    return (i < j ? i : j);
}

int MaximumRepresentation(char *s, int l)
{
    int i = 0, j = 1, k = 0, t;
    while(i < l && j < l && k < l) {
        t = s[(i + k) >= l ? i + k - l : i + k] - s[(j + k) >= l ? j + k - l : j + k];
        if(!t) k++;
        else{
            if(t < 0) i = i + k + 1;
            else j = j + k + 1;
            if(i == j) ++ j;
            k = 0;
        }
    }
    return (i < j ? i : j);
}

void getfail(char *p, int *f)
{
    int m = strlen(p);
    f[0]=0;f[1]=0;
    for(int i=1;i<m;++i)
    {
        int j = f[i];
        while(j && p[i]!=p[j])  j=f[j];
        f[i+1] = p[i] == p[j]?j+1:0;
    }
}
int find(char *t, char *p, int *f)
{
    int n = strlen(t), m = strlen(p);
    getfail(p,f);
    int j=0, res=0;;
    for(int i=0;i<n;++i)
    {
        while(j && p[j]!=t[i])  j=f[j];
        if(p[j]==t[i])  j++;
        if(j==m)    ++res,j=f[j];
    }
    return res;
}

int getnum(int idx)
{
    strcpy(s2,s+idx);
    strncat(s2,s,idx);
//    cout<<s2<<endl;
    return find(s3,s2,f);
}

void run()
{
    l = strlen(s);
    strcpy(s3,s);
    strcat(s3,s);
    s3[2*l-1]='\0';
//    cout<<s3<<endl;
    minidx = MinimumRepresentation(s,l);
    minnum = getnum(minidx);
    maxidx = MaximumRepresentation(s,l);
    maxnum = getnum(maxidx);
    printf("%d %d %d %d\n",minidx+1,minnum,maxidx+1,maxnum);
}

int main()
{
    while(scanf("%s",s)!=EOF)
        run();
    return 0;
}
