#include <stdio.h>
// two-dimensional arrays

int main()
{
    int a[3][4]={{1,3,5,7},{9,11,13,15},{17,19,21,23}};
    //int a[5]={1,2,3,4,5};
    printf(" a[1]:%d \n a:%d \n *a:%d \n a+1:%d \n *a+1:%d \n *(a+1):%d \n a[2]+1:%d \n *(a+1)+1:%d \n",a[1],a,*a,a+1,*a+1,*(a+1),a[2]+1,*(a+1)+1);
    printf(" *(*(a+2)+2):%d \n",*(*(a+2)+2));

    printf("&a:%d,&a[0]:%d \n",&a,&a[0]);
    printf("a:%d,a[0]:%d \n",a,a[0]);
    printf("*a:%d,*a[0]:%d \n",*a,*a[0]);
    printf("**a:%d \n",**a);
    printf("size of a:%d,size of a[0]:%d \n",sizeof(a),sizeof(a[0]));
    return 0;
}

//ont-dimensional array
/*int main()
{
    int a[3]={1,2,3};
    printf("&a:%d,&a[0]:%d \n",&a,&a[0]);
    printf("a:%d,a[0]:%d \n",a,a[0]);
    printf("*a:%d \n",*a);
    return 0;
}*/
