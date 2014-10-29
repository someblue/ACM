#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000
int hp_acmer,hp_boss,boss[MAXN],acmer[MAXN];

int damage(int is_boss,int i)//is boss damaged?
{
    if(is_boss)
    {
        hp_boss -= acmer[i];
        return hp_boss;
    }
    else
    {
        hp_acmer -= boss[i];
        return hp_acmer;
    }
}

int main()
{
    int num;
    int i;
    scanf("%d%d%d",&hp_acmer,&hp_boss,&num);
    for(i=0;i<num;i++)
        scanf("%d",&boss[i]);
    for(i=0;i<num;i++)
        scanf("%d",&acmer[i]);
    for(i=0;i<num;i++)
    {
        if(boss[i]>0&&acmer[i]>0)
        {
            if(boss[i]>acmer[i])
            {
                if(damage(0,i)<0)
                {
                    printf("boss\n");
                    return 0;
                }
            }
            else if(boss[i]<acmer[i])
                if(damage(1,i)<0)
                {
                    printf("acmer\n");
                    return 0;
                }
        }
        else if(boss[i]<0&&acmer[i]<0);
        else
        {
            if(acmer[i]>0)
            {
                if(acmer[i]> 0-boss[i])
                    if(damage(1,i)<0)
                    {
                        printf("acmer\n");
                        return 0;
                    }
            }
            else
            {
                if(boss[i]>0-acmer[i])
                    if(damage(0,i)<0)
                    {
                        printf("boss\n");
                        return 0;
                    }
            }
        }
    }
    printf("impossible\n");
    return 0;
}
