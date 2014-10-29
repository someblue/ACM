#include <iostream>
#include <cstdio>
using namespace std;
int a[100010],d[100010];//a[] is shop, d is list[]
bool f[100010],g[100010];
int main()
{
    int n,m,k,sum,x;
    bool flag;
    while(scanf("%d%d",&n,&m)!=EOF)//n,shop number. m,check number
    {
        if(n==0&&m==0)  break;
        for(int i=1; i<=n; i++)  scanf("%d",&a[i]);//input shop[]
        while(m--)
        {
            for(int i=1; i<=n; i++)//initialize
            {
                d[i]=0;
                f[i]=g[i]=false;
            }
            flag=false;
            sum=0;
            scanf("%d",&k);//k,list number
            for(int i=1; i<=k; i++)
            {
                scanf("%d",&x);//input list[]
                if(!f[x])
                {
                    f[x]=true;//记录查询区间里面要查询的数
                    g[x]=true;//为了初始化pt2的值
                    sum++;
                }
            }
            int s=0,pt1=1,pt2=1;
            for(; s<sum; pt2++)
            {
                d[a[pt2]]++;//确定每个数出现的次数
                if(g[a[pt2]])
                {
                    s++;
                    g[a[pt2]]=false;
                }
            }
            pt2--;
            int ans=pt2;
            if(pt2==1) flag=true;
            for(; pt1<=pt2&&!flag; pt1++)
            {
                d[a[pt1]]--;
                if(f[a[pt1]]&&!d[a[pt1]])
                {
                    if(ans>pt2-pt1+1)
                    {
                        ans=pt2-pt1+1;
                        if(ans==1)
                        {
                            flag=true;
                            break;
                        }
                    }
                    pt2++;
                    while(pt2<=n&&!flag)
                    {
                        d[a[pt2]]++;
                        if(a[pt2]==a[pt1])  break;
                        pt2++;
                    }
                    if(!d[a[pt1]]) flag=true;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
