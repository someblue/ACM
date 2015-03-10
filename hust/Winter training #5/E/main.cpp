#include <bits/stdc++.h>
using namespace std;
const int N = 35;

char s[N], word[N][N];
int n, sz;
vector<int> pipei[N];

//int st[N][N]; // 0 bi bai, 1 bi sheng

int sg[N][N];

inline bool judge_pipei(int w, int pos, int szz)
{
    for(int i=0; i<szz; i++)
        if(word[w][i] != s[pos+i])
            return 0;
    return 1;
}

int get(int l, int r)
{
    if(sg[l][r]!=-1)
        return sg[l][r];
    if(l>=r)
        return sg[l][r]=0;
    set<int> vis;
    for(int i=l; i<r; i++)
        for(int j=0; j<pipei[i].size(); j++)
            vis.insert(get(l,i) ^ get(pipei[i][j],r));
    for(int i=0; ; i++)
        if(!vis.count(i))
            return sg[l][r] = i;
}

void run()
{
    scanf("%s",s);
    sz = strlen(s);
    for(int i=0; i<sz; i++)
        pipei[i].clear();
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s",word[i]);
        int sz2 = strlen(word[i]);
        for(int j=0; j<=sz-sz2; j++)
            if(judge_pipei(i, j, sz2))
                pipei[j].push_back(j+sz2);
    }
    memset(sg,-1,sizeof(sg));
    printf("%s\n", get(0,sz)? "Teddy":"Tracy");
//    for(int i=0; i<sz; i++)
//    {
//        for(int j=0; j<=sz; j++)
//            cout << sg[i][j] << ' ';
//        cout <<endl;
//    }
}

int main()
{
    freopen("case.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
