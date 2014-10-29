/*
*State: 1848    0MS    320K    994 B    C++
*��Ŀ���⣺
*        ����3�����ӣ�ÿ�ο��Դ�ÿһ������쳲����������ӣ����
*        ��ȡ����ʤ���жϸþ��Ƿ�Ϊ������ƣ�P��N�㣩��
*����˼·��
*        ���͵���sg����������⡣
*/
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX = 1024;
int sg[MAX];

void pre_init()
{
    int fib[1024];
    fib[0] = fib[1] = 1;
    for(int i = 2; i < 1024; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    bool vis[MAX] = {false};
    for(int i = 0; i < MAX; i++)
    {
        int h = 1;
        memset(vis, false, sizeof(vis));
        while(i >= fib[h])
        {
            int tmp = i - fib[h++];
            vis[sg[tmp]] = true;
        }
        int j;
        for(j = 0; j <= i; j++)
        {
            if(vis[j] == false)
                break;
        }
        sg[i] = j;
    }
    return ;
}

void view_arr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << endl;
    return ;
}

int main(void)
{
    pre_init();
    view_arr(sg, 20);
    int a[3];
    while(scanf("%d %d %d", &a[0], &a[1], &a[2]) == 3)
    {
        if(!(a[0] || a[1] || a[2]))
            break;
        int yihuo = 0;
        for(int i = 0; i < 3; i++)
        {
            yihuo ^= sg[a[i]];
        }
        if(!yihuo)
            printf("Nacci\n");
        else
            printf("Fibo\n");
    }
    return 0;
}
