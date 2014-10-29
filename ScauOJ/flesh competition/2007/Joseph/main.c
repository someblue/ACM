#include <stdio.h>
#include <stdlib.h>

int main()
{
    int child[31],n,s,m;
    int i;
    scanf("%d%d%d",&n,&s,&m);
    m--;
    for(i=1;i<=n;i++)
        child[i]=i;
    do
    {
        s=(s+m)%n;
        //printf("s:%d,child[s]:%d\n",s,child[s]);
        if(s==0)
            {s=1;
            //printf("----%d",child[s]);
            }
        else
        {
            for(i=s;i<n;i++)
                child[i]=child[i+1];
        }
        n--;
        //printf("n:%d\n",n);
    }
    while(n>1);
    printf("%d\n",child[1]);
    return 0;
}
