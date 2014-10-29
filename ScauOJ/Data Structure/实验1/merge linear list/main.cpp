#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
} SqList;

int Load_Sq(SqList &L)
{
// 输出顺序表中的所有元素
	int i;
	if(L.length==0) printf("The List is empty!");  // 请填空
	else
		for(i=0;i<L.length;i++) printf("%d ",*(L.elem+i));  // 请填空
	printf("\n");
	return OK;
}

Status InitList_Sq(SqList &L)
{
    // 算法2.3
    // 构造一个空的线性表L。
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!L.elem) return OK;        // 存储分配失败
    L.length = 0;                  // 空表长度为0
    L.listsize = LIST_INIT_SIZE;   // 初始存储容量
    return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    // 算法2.4
    // 在顺序线性表L的第i个元素之前插入新的元素e，
    // i的合法值为1≤i≤ListLength_Sq(L)+1
    ElemType *p;
    if (i < 1 || i > L.length+1) return ERROR;  // i值不合法
    if (L.length >= L.listsize)     // 当前存储空间已满，增加容量
    {
        ElemType *newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof (ElemType));
        if (!newbase) return ERROR;   // 存储分配失败
        L.elem = newbase;             // 新基址
        L.listsize += LISTINCREMENT;  // 增加存储容量
    }
    ElemType *q = &(L.elem[i-1]);   // q为插入位置
    for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
    // 插入位置及之后的元素右移
    *q = e;       // 插入e
    ++L.length;   // 表长增1
    return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    // 算法2.5
    // 在顺序线性表L中删除第i个元素，并用e返回其值。
    // i的合法值为1≤i≤ListLength_Sq(L)。
    ElemType *p, *q;
    if (i<1 || i>L.length) return ERROR;  // i值不合法
    p = &(L.elem[i-1]);                   // p为被删除元素的位置
    e = *p;                               // 被删除元素的值赋给e
    q = L.elem+L.length-1;                // 表尾元素的位置
    for (++p; p<=q; ++p) *(p-1) = *p;     // 被删除元素之后的元素左移
    --L.length;                           // 表长减1
    return OK;
} // ListDelete_Sq

Status mergeList(SqList &la,SqList &lb,SqList &lc)
{
    int p,q,lena,lenb;
    lena=la.length;lenb=lb.length;
    p=q=0;
    while(p<lena&&q<lenb)
    {
        if(la.elem[p]<=lb.elem[q])
            ListInsert_Sq(lc,lc.length+1,la.elem[p++]);
        else
            ListInsert_Sq(lc,lc.length+1,lb.elem[q++]);
    }
    while(p<lena)
        ListInsert_Sq(lc,lc.length+1,la.elem[p++]);
    while(q<lenb)
        ListInsert_Sq(lc,lc.length+1,lb.elem[q++]);
    return OK;
}

int main()
{
    freopen("case.txt","r",stdin);
    int numa,numb,pst,t;
    SqList Ta,Tb,Tc;
    InitList_Sq(Ta);
    InitList_Sq(Tb);
    InitList_Sq(Tc);
    scanf("%d",&numa);
    for(pst=1;pst<=numa;pst++)
    {
        scanf("%d",&t);
        ListInsert_Sq(Ta,pst,t);
    }
    scanf("%d",&numb);
    for(pst=1;pst<=numb;pst++)
    {
        scanf("%d",&t);
        ListInsert_Sq(Tb,pst,t);
    }
    mergeList(Ta,Tb,Tc);
    printf("List A:");Load_Sq(Ta);
    printf("List B:");Load_Sq(Tb);
    printf("List C:");Load_Sq(Tc);
    return 0;
}

/*
第一行：顺序表A的元素个数
第二行：顺序表A的各元素（非递减），用空格分开
第三行：顺序表B的元素个数
第四行：顺序表B的各元素（非递减），用空格分开
*/
