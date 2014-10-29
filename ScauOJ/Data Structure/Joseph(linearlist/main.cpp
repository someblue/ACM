#include <stdio.h>
#include <malloc.h>
#include <vector>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int
using namespace std;

vector<int> order;

typedef struct
{
	int *elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L)
{
// 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE
// 请补全代码
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) return ERROR;
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

int Load_Sq(SqList &L)
{
// 输出顺序表中的所有元素
	int i;
	if(L.length==0) printf("The List is empty!");  // 请填空
	else
	{
		printf("The List is: ");
		for(i=0;i<L.length;i++) printf("%d ",*(L.elem+i));  // 请填空
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
// 算法2.4，在顺序线性表L中第i个位置之前插入新的元素e
// i的合法值为1≤i≤L.length +1
// 请补全代码
    if(i<1||i>L.length+1) return ERROR;
    if(L.length>=L.listsize)
    {
        ElemType *newbase;
        newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(newbase==NULL) return ERROR;
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    ElemType *q,*p;
    q=(L.elem+i-1);
    for(p=(L.elem+L.length-1);p>=q;p--)
        *(p+1)=*p;
    *q=e;
    L.length++;
    return OK;
}

int ListDelete_Sq(SqList &L,int i, int &e)
{
// 算法2.5,在顺序线性表L中删除第i个位置的元素，并用e返回其值
// i的合法值为1≤i≤L.length
// 请补全代码
    if(i<1||i>L.length) return ERROR;
    ElemType *p,*q;
    q=(L.elem+i-1);
    e=*q;
    p=(L.elem+L.length-1);
    for(q++;q<=p;q++)
        *(q-1)=*q;
    L.length--;
    return OK;
}

void next_iter(SqList &L,int &it)
{
    it++;
    if(it>L.length) it=1;
}

void print_order()
{
    unsigned int i;
    for(i=0;i!=order.size();i++)
        printf("%d ",order[i]);
    printf("\n");
}

void run()
{
    int n,s,k,e,it;
    int i;
    SqList L;
    order.clear();
    scanf("%d%d%d",&n,&s,&k);
    InitList_Sq(L);
    for(i=1;i<=n;i++) {ListInsert_Sq(L,i,i);}
    it=1;
    for(i=0;i<s-1;i++)
        next_iter(L,it);
    while(L.length)
    {
        for(i=0;i<k-1;i++)
            next_iter(L,it);
        ListDelete_Sq(L,it,e);
        order.push_back(e);
        if(it>L.length) it=1;
    }
    print_order();
}

int main()
{
    run();
    return 0;
}
