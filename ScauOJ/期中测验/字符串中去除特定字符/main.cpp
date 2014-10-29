#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char c;
    while(c=getchar(),c!='\n')
    {
        if(c!='A')
            cout<<c;
    }
    return 0;
}
