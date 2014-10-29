#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
    int n,temp,*ans;
    int i;
    while(cin>>n,n!=0)
    {
        queue<int> q;
        ans=(int*)malloc((n+1)*sizeof(int));
        for(i=n;i>=1;i--)
        {
            if(!q.empty())
            {
                temp=q.front();
                q.pop();
                q.push(temp);
            }
            q.push(i);
        }
        for(i=0;!q.empty();i++)
        {
            *(ans++)=q.front();
            q.pop();
        }
        for(;i>0;i--)
            cout<<*(--ans)<<' ';
        cout<<endl;
    }
    return 0;
}
