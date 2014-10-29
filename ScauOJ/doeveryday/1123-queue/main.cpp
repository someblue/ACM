#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node
{
    friend bool operator < (node n1,node n2)
    {
        return (n1.p<n2.p)||(n1.p==n2.p&&n1.k>n2.k);
    }
    int k,p;
};

int main()
{
    //freopen("case.txt","r",stdin);
    node t;
    priority_queue<node> doc[4];
    int T,d,p,cnt,i,s;
    char c[5];
    while(scanf("%d",&T)!=EOF)
    {
        cnt=1;
        while(T--)
        {
            scanf("%s",c);
            if(strcmp(c,"IN")==0)
            {
                scanf("%d%d",&d,&p);
                t.k=cnt++;
                t.p=p;
                doc[d].push(t);
            }
            else
            {
                scanf("%d",&d);
                if(doc[d].empty())
                    printf("EMPTY\n");
                else
                {
                    printf("%d\n",doc[d].top().k);
                    doc[d].pop();
                }
            }
        }
        for(i=1;i<=3;i++)
        {
            s=doc[i].size();
            while(s--)
                doc[i].pop();
        }
    }
    return 0;
}
