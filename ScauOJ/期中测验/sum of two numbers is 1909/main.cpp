#include <iostream>

using namespace std;

int main()
{
    int num[10];
    int i,j;
    for(i=0;i<10;i++)
        cin>>num[i];
    for(i=0;i<10;i++)
    {
        for(j=i+1;j<10;j++)
            if(num[i]+num[j]==1909)
            {
                cout<<"Y"<<endl;
                return 0;
            }
    }
    cout<<"N"<<endl;
    return 0;
}
