#include <stdio.h>
#include <stdlib.h>
/*input example1
2 3 5 7 11 13 17 19
1 1 1 1 1 1 1 1
output example1
9699691
*/

/*input example2
2 3 5 7 11 13 17 19
1 1 2 5 8 9 12 9
output example2
2831617
*/

struct{
    int a;
    int b;
    int c;
    long long A;
}num[8];

int max_a()
{
    int max=-1,i;
    for(i=0;i<8;i++)
        if(num[i].a>max)
            max=num[i].a;
    return max;
}
long long select()
{
    long long w,q;
    int i,j,max;
    q=1;
    for(i=0;i<8;i++)
        q *= num[i].a;
    //printf("q:%I64d\n",q);//print q
    for(i=0;i<8;i++)
        num[i].A=q/num[i].a;
    for(i=0;i<8;i++)
    {
        for(j=0;;j++)
            if(j*num[i].A%num[i].a==num[i].b)
            {
                num[i].c=j;
                //printf("%d\n",j);
                break;
            }
    }
    w=0;
    for(i=0;i<8;i++)
        w += num[i].A*num[i].c;
    //printf("w:%I64d\n",w);//print q-----------
    max=max_a();
    w =w%q;
    if(w<max)
    {
        w += q;
    }
    return w;
}

int main()
{
    int i;
    for(i=0;i<8;i++)
        scanf("%d",&num[i].a);
    for(i=0;i<8;i++)
        scanf("%d",&num[i].b);
//    sort();
    printf("%I64d\n",select());
    return 0;
}
