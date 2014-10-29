#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y,m,d,t;
    int isrun;
    int moun[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&y,&m,&d);
        //printf("%d,%d,%d",y,m,d);
        if(y%4==0)
        {
            if(y%100==0)
            {
                if(y%400==0)
                    isrun=1;
                else isrun=0;
            }
            else isrun=1;
        }
        else isrun=0;
        int i,j,sum=0;
        for(i=0;i<m-1;i++)
        {
            sum+=moun[isrun][i];
        }
        sum+=d;
        printf("%d\n",sum);
    }
    return 0;
}
