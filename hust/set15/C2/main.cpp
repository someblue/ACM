#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int N = 155;
const int LEN = 75;
const int maxnode = N*LEN;

map<string,int> ms;
struct ACM{
    int ch[maxnode][30];
    int val[maxnode],f[maxnode],last[maxnode],cnt[N];
    int sz;
    static const int sigma_size=26;
    void init()
    {
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
        memset(cnt,0,sizeof(cnt));
        memset(val,0,sizeof(val));
        ms.clear();
    }
    int idx(char c)
    {
        return c-'a';
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
        ms[string(s)]=k;
        val[u]=k;
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
            while(j && !ch[j][c])   j=f[j];
            j=ch[j][c];
            if(val[j]) print(j);
            else if(last[j])    print(last[j]);
        }
    }
    void print(int j)
    {
        if(j)
        {
            cnt[val[j]]++;
            print(last[j]);
        }
    }
};

ACM ac;
char s[N][LEN],text[1000005];
int n;
map<string,int> mymap;

int main()
{
    while(scanf("%d",&n)!=EOF && n)
    {
        ac.init();
        mymap.clear();
        for(int i=1;i<=n;++i)
        {
            scanf("%s",s[i]);
            ac.insert(i,s[i]);
        }
        ac.getFail();
        scanf("%s",text);
        ac.find(text);
        int maxx = -1;
        for(int i=1;i<=n;++i)
            if(ac.cnt[i] > maxx)    maxx=ac.cnt[i];
        printf("%d\n",maxx);
        for(int i=1;i<=n;++i)
            if(ac.cnt[ms[string(s[i])]]==maxx)
                printf("%s\n",s[i]);
    }
    return 0;
}
