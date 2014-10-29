#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char num[11];
    int i;
    cin>>num;
    sort(num,num+strlen(num));
    for(i=0;num[i]!='\0';i++)
    {
        if(num[i]!='0')
            cout<<num[i];
    }
    return 0;
}
