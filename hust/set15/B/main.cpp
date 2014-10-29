#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1005;
const int LEN = 55;
const int maxnode = N*LEN;

struct ACM{
    int ch[maxnode][30];
    int val[maxnode],f[maxnode],last[maxnode],mp[N];
    int sz;
    int ans;
    static const int sigma_size=26;
    void init() {sz=1;memset(ch[0],0,sizeof(ch[0]));ans=0;}
    int idx(char c)
    {
        if(c>='A' && c<='Z')    return c-'A';
        else return -1;
    }
    void insert(int k, char *s)
    {
        int u=0,n=strlen(s);
        for(int i=0;i<n;++i)
        {
            int c = idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=1;
        mp[k]=u;
    }
    void getFail()
    {
        queue<int> q;
        f[0]=0;
        for(int c=0;c<sigma_size;++c)
        {
            int u=ch[0][c];
            if(u)   {f[u]=0;q.push(u);last[u]=0;}
        }
        while(!q.empty())
        {
            int r=q.front(); q.pop();
            for(int c=0;c<sigma_size;++c)
            {
                int u=ch[r][c];
                if(!u)  continue;
                q.push(u);
                int v=f[r];
                while(v && !ch[v][c])   v=f[v];
                f[u]=ch[v][c];
                last[u]=val[f[u]]?f[u]:last[f[u]];
            }
        }
    }
    void find(char *t)
    {
        int n=strlen(t);
        int j=0;
        for(int i=0;i<n;++i)
        {
            int c=idx(t[i]);
            if(c==-1)   j=0;
            else
            {
                while(j && !ch[j][c])   j=f[j];
                j=ch[j][c];
            }
            if(val[j]) print(j);
            else if(last[j])    print(last[j]);
        }
    }
    void print(int j)
    {
        if(j)
        {
            ++val[j];
            print(last[j]);
        }
    }
};

ACM ac;
char s[N][LEN],ms[2000005];
int n;

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        ac.init();
        for(int i=0;i<n;++i)
        {
            scanf("%s",s[i]);
            ac.insert(i,s[i]);
        }
        scanf("%*c");
        ac.getFail();
//        scanf("%s",ms);
        gets(ms);
        ac.find(ms);
        for(int i=0;i<n;++i)
        {
            if(ac.val[ac.mp[i]]==1)   continue;
            else
                printf("%s: %d\n",s[i],ac.val[ac.mp[i]]-1);
        }
    }
    return 0;
}
