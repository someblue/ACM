#include <stdio.h>
#include <math.h>
//9592 prime numbers between 1-100000
int prime[9593];

void create_prime_table()
{
    prime[0]=2;prime[1]=3;prime[9592]=100001;
    int i,j,flag,n,counter=2;
    double sqrtn;
    for(i=2;counter<9592;i++)
    {
        //------------------6n-1------------------
        flag=1;
        n=6*(i-1)-1;
        sqrtn=sqrt(n);
        for(j=0;prime[j]<=sqrtn;j++)
            if(n%prime[j]==0)
            {
                flag=0;
                break;
            }
        if(flag)
        {
            prime[counter]=n;
            counter++;
        }
        //------------------6n+1------------------
        flag=1;
        n=6*(i-1)+1;
        sqrtn=sqrt(n);
        for(j=0;prime[j]<=sqrtn;j++)
            if(n%prime[j]==0)
            {
                flag=0;
                break;
            }
        if(flag)
        {
            prime[counter]=n;
            counter++;
        }
    }
}

void print_prime(int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d:%d\n",i,prime[i]);
}

int number(int n,int left,int right)
{
    int mid;
    mid=(left+right)/2;
//    if(prime[left]<=n&&prime[left+1]>n)
//        return left;
//    if(prime[right]<=n&&prime[right+1]>n)
//        return right;
    if(prime[mid]<=n&&prime[mid+1]>n)
        return mid;
    if(prime[mid+1]<=n)
        return number(n,mid,right);
    if(prime[mid]>n)
        return number(n,left,mid);
    return -1;
}

int main()
{
    create_prime_table();
    int i,T,n;
    //print_prime(20);//use for text
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        if(n==1) printf("0\n");
        else printf("%d\n",number(n,0,9592)+1);
    }

//    for(i=0;i<100000;i++)
//        number(100000,0,9592);
    return 0;
}
