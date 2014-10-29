#include <bits/stdc++.h>
using namespace std;
const int N = 6000;

struct _node {
    int x1,y1,x2,y2;
    bool operator < (const _node &b) const
    {
        return x1<b.x1 || (x1==b.x1 && y2<b.y2);
    }
};
vector<_node> spec;
int row[N],col[N],rowcnt,colcnt;
int r,c;
int vis[N];

void init()
{
    int i;
    for(i=1;i<=r;++i)   row[i]=i;
    for(i=1;i<=c;++i)   col[i]=i;
    rowcnt=colcnt=0;
    spec.clear();
}

inline void ins(int *arr,int len)
{
    memset(vis,0,sizeof(vis));
    int n,x,i;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        vis[x]=1;
    }
    for(i=1;i<N;++i)
        vis[i]+=vis[i-1];
    for(i=1;i<=len;++i)
        if(arr[i]>0)
            arr[i]+=vis[arr[i]];
}

inline void del(int *arr,int len,int &cnt)
{
    memset(vis,0,sizeof(vis));
    int n,x,i;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        vis[x]=1;
    }
    for(i=1;i<N;++i)
        vis[i]+=vis[i-1];
    for(i=1;i<=len;++i)
    {
        if(arr[i]==-1) continue;
        if(vis[arr[i]-1]!=vis[arr[i]])
            arr[i]=-1,cnt--;
        else
            arr[i]-=vis[arr[i]];
    }
}

void ex()
{
    _node tmp;
    scanf("%d%d%d%d",&tmp.x1,&tmp.y1,&tmp.x2,&tmp.y2);
    spec.push_back(tmp);
}

int left_num,dis;
void deal()
{
    left_num =
}

void find(int x,int y)
{

}

void run()
{
    init();
    int m;
    char s[5];
    scanf("%d",&m);
    while(m--)
    {
        scanf("%s",s);
        if(s[0]=='D')
            del(s[1]=='R'?row:col,s[1]=='R'?r:c,s[1]=='R'?rowcnt:colcnt);
        else if(s[0]=='I')
            ins(s[1]=='R'?row:col,s[1]=='R'?r:c);
        else
            ex();
        for(int i=1;i<=r;++i)   cout<<row[i]<<' ';  cout<<endl;
        for(int i=1;i<=c;++i)   cout<<col[i]<<' ';  cout<<endl;
    }
//    for(int i=1;i<=r;++i)   cout<<row[i]<<' ';  cout<<endl;
//    for(int i=1;i<=c;++i)   cout<<col[i]<<' ';  cout<<endl;
//    deal();
//    static int cas=1;
//    printf("Spreadsheet #%d\n",cas++);
//    printf("There are %d cell(s) kept, total\n",left_num);
//    printf("distance = %d\n",dis);
//    scanf("%d",&m);
//    int x,y;
//    while(m--)
//    {
//        scanf("%d%d",&x,&y);
//        printf("Cell data in (%d,%d) ",x,y);
//        find(x,y);
//        if(x==-1)   puts("GONE");
//        else    printf("moved to (%d,%d)\n",x,y);
//    }
}

int main()
{
    freopen("in","r",stdin);
    while(scanf("%d%d",&r,&c)!=EOF && r && c)
        run();
    return 0;
}
