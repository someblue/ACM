#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    printf("%s\n",rand()%2?"YES":"NO");
    return 0;
}
