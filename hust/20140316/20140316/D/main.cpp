#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int num[3],n;
    scanf("%d%d%d%d",&n,&num[0],&num[1],&num[2]);
    sort(num,num+3);
    int a,b,c;
    int i,j,k,maxn;
    a=num[0];
    b=num[1];
    c=num[2];
    if(n%a==0)
    {
        printf("%d\n",n/a);
        return 0;
    }
    maxn=n/a;
//    for(k=0;k*c<=n;k++)
//    {
//        for(j=0;k*c+j*b<=n;j++)
//        {
//            if((n-k*c-j*b)%a==0)
//                {
//                    printf("%d\n",j+k+(n-k*c-j*b)/a);
//                    return 0;
//                }
//        }
//    }
    for(i=maxn;i>=0;i--)
    {
        if((n-a*i)%b==0)
        {
            printf("%d\n",i+(n-a*i)/b);
            return 0;
        }
        for(j=(n-a*i)/b;j>=0;j--)
        {
            if((n-a*i-b*j)%c==0)
            {
                printf("%d\n",i+j+(n-a*i-b*j)/c);
                return 0;
            }
        }
    }
    return 0;
}

/*
WA
*/
