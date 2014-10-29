#include "stdio.h"
#include "malloc.h"
#define LEN sizeof(struct student)

struct student
{
     long num;
     int score;
     struct student *next;
};

struct student *creat(int n)
{
     struct student *head=NULL,*p1=NULL,*p2=NULL;
     int i;
     for(i=1;i<=n;i++)
     {  p1=(struct student *)malloc(LEN);
        scanf("%ld",&p1->num);
        scanf("%d",&p1->score);
        p1->next=NULL;
        if(i==1) head=p1;
        else p2->next=p1;
        p2=p1;
      }
      return(head);
}

void print(struct student *head)
{
    struct student *p;
    p=head;
    while(p!=NULL)
    {
        printf("%8ld%8d",p->num,p->score);
        p=p->next;
        printf("\n");
    }
}

//this my way
struct student *insert(struct student *head, struct student *stud)
{
    if(head->num > stud->num)//��������Ҫ��Ϊ����ͷʱ
    {
        stud->next = head;
        return stud;
    }
    struct student *p1=head,*p2;
    while(p1->num < stud->num&&p1->next!=NULL)//�������������м�ʱ
    {
        p2=p1;
        p1=p1->next;
    }
    if(p1->next!=NULL || p1->num > stud->num)
    {
        p2->next = stud;
        stud->next = p1;
        return head;
    }
    else //if(p1->next==NULL && p1->num < stud->num)//��������Ҫ��Ϊ����βʱ
    {
        p1->next=stud;
        return head;
    }
}

//this the textbook's way and this is better
struct student *insert(struct student *head, struct student *stud)
{
    struct student *ptr,*ptr1,*ptr2;

    ptr2=head;
    ptr=stud;//ptrָ����������ѧ����¼���
    while((ptr->num>ptr2->num)&&(ptr2->next!=NULL))
    {
        ptr1=ptr2;//ptr1,ptr2������һ�����
        ptr2=ptr2->next;
    }
    if(ptr->num<=ptr2->num)//��ptr1��ptr2֮������½��
    {
        if(head==ptr2) head=ptr;
        else ptr1->next=ptr;
        ptr->next=ptr2;
    }
    else//�²������Ϊβ���
    {
        ptr2->next=ptr;
        ptr->next=NULL;
    }
    return head;
}

main()
{
    struct student *head,*stu;
    int n;
    scanf("%d",&n);
    head=creat(n);
    print(head);
    stu=(struct student *)malloc(LEN);
    scanf("%ld",&stu->num);
    scanf("%d",&stu->score);
    stu->next = NULL;
    head=insert(head,stu);
    print(head);
}
