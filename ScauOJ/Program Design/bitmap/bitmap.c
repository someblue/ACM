#include <stdio.h>

int main()
{
    int num[7] = {0};
    int i,j,k,n;
    int grp,offset;
    for(i=0;i<9;)
    {
        n = (rand() % 51) + 1;

        grp = n / 8;
        offset = n % 8;

        if((num[grp] >> (7-offset)) & 1)
            continue;
        else
        {
            num[grp] |= (1 << (7-offset));
            printf("%d\n",n);
            i++;
        }
    }
}
