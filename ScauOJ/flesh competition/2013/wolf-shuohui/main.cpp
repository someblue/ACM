#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int s[1010][1010];
int p[1010];
int q[1010];
int x;
int main()
{
    int t,n,k,i,j,max,c,lang,z;
    char str[5];
    scanf("%d",&t);
    while(t--)
    {
        z=0;
        memset(p,0,sizeof(p));
        memset(q,0,sizeof(q));
        scanf("%d%d",&n,&k);
        for(i=1;i<=k;i++)
        {
            scanf("%d",&x);
            p[x]=1;
            for(j=1;j<=n;j++)scanf("%d",&s[i][j]);
        }
        getchar();
        gets(str);
        if(strcmp(str,"hehe")==0)
        {
                for(i=1;i<=n;i++)if(s[k][i]!=-1)q[s[k][i]]++;
                for(max=1,i=2;i<=n;i++)if(q[i]>q[max])max=i;lang=max;
                for(i=1;i<=n;i++)if(s[k][i]!=-1&&i!=lang)p[i]=1;
                for(i=1;i<k;i++)
                    {
                         p[s[i][lang]]=1;
                         for(j=1;j<=n;j++)if(s[i][j]!=s[i][lang]&&s[i][j]!=-1)p[j]=1;
                    }
        }
        else
        {
                if(s[k][1]==0)
                {
                    if(k>1)
                    {
                        for(i=1;i<=n;i++)if(s[k-1][i]!=-1)q[s[k-1][i]]++;
                        for(max=1,i=2;i<=n;i++)if(q[i]>q[max])max=i;
                        p[max]=1;
                        for(i=1;i<=n;i++)if(s[k-1][i]!=-1&&i!=x&&i!=max){lang=i;break;}
                        for(i=1;i<k;i++)
                        {
                         p[s[i][lang]]=1;
                         for(j=1;j<=n;j++)if(s[i][j]!=s[i][lang]&&s[i][j]!=-1)p[j]=1;
                        }
                    }
                }
                else
                {
                    for(i=1;i<=n;i++)if(s[k][i]!=-1)q[s[k][i]]++;
                    for(max=1,i=2;i<=n;i++)if(q[i]>q[max])max=i;
                    p[max]=1;
                    for(i=1;i<=n;i++)if(s[k][i]!=-1&&i!=max){z++;lang=i;}
                    for(i=1;i<=k;i++)
                         {
                         p[s[i][lang]]=1;
                         for(j=1;j<=n;j++)if(s[i][j]!=s[i][lang]&&s[i][j]!=-1)p[j]=1;
                    }
                }
        }
        for(c=0,i=1;i<=n;i++)if(!p[i])c++;
        if(c<z)c=z;
        printf("%d\n",c);
    }
    return 0;
}
