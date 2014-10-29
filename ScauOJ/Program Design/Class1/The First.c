#include <stdio.h>
/*将显示窗口属性改为只显示一行*/
void wait(int n)
{
    int j;
    for(j=0;j<n;j++) j=j;
}
int main()
{
     while(1)
     {
         printf("\nhello");
         wait(100000000);
         printf("\nello h");
         wait(100000000);
         printf("\nllo he");
         wait(100000000);
         printf("\nlo hel");
         wait(100000000);
         printf("\no hell");
         wait(100000000);
         printf("\n hello");
         wait(100000000);
     }
        return 0;
}
