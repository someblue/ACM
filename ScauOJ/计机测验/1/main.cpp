#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char s[100];
    int i,sum=0;
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            sum+=s[i]-'0';

    }
    cout<<sum<<endl;
    return 0;
}
