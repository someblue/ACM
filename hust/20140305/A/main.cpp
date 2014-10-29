#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[110];
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(strlen(s)<=10){cout<<s<<endl;continue;}
        cout<<s[0]<<strlen(s)-2<<s[strlen(s)-1]<<endl;
    }
    return 0;
}
