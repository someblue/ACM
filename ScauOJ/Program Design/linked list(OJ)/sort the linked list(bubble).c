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

struct student *insert(struct student *head, struct student *stud)
{  struct student *p0,*p1,*p2;
    p1=head;  p0=stud;
    if(head==NULL)
      {head=p0;}
    else
   { while( (p0->num > p1->num) && (p1->next!=NULL) )
       { p2=p1;     p1=p1->next;}
     if( p0->num < p1->num )
      {  if( head==p1 ) head=p0;
           else p2->next=p0;
         p0->next=p1; }
     else {  p1->next=p0;}
     }
    return(head);
}

struct student *del(struct student *head,long num)
{
    struct student *p1,*p2;
    p1=head;
    while(p1!=NULL)
    {
        if(p1->num == num)
        {
          if(p1 == head) head=p1->next;
          else p2->next=p1->next;
          free(p1);
          break;
        }
        p2=p1;
        p1=p1->next;
    }
    return(head);
}

//my way...like a shit...
struct student *sort(struct student *head)//from small to large
{
    struct student *temp,*tempname,*tempcounter,*p1,*p2,*p3;
    int counter=0,i,j;
    temp=(struct student *)malloc(LEN);
    //求结点数
    tempcounter=head;
    while(tempcounter->next!=NULL)
    {
        tempcounter=tempcounter->next;
        counter++;
    }
    //sort
    for(i=0;i<counter;i++)
    {
        p1=head;
        p2=head->next;
        if(p1->num > p2->num)
        {
            p1->next=p2->next;
            p2->next=p1;
            head=p2;
        }
        p1=head->next;
        p2=p1->next;
        p3=head;
        for(j=0;j<counter-i-1;j++)
        {
            if(p1->num > p2->num)
            {
                //exchange all
                temp->next=p3->next;
                p3->next=p1->next;
                p1->next=p2->next;
                p2->next=temp->next;
                //exchange name
                tempname=p2;
                p2=p1;
                p1=tempname;
            }
            p1=p1->next;
            p2=p2->next;
            p3=p3->next;
        }
    }
    free(temp);
    return head;
}
//VM's way.very very very easy!
//struct student *sort(struct student *head)
//{
//    struct student *h2,*t,*p;
//    h2=NULL;p=head;
//    while(p!=NULL){
//        t=p;p=p->next;t->next=NULL;
//        h2=insert(h2,t);
//    }
//    return h2;
//}

main()
{
    struct student *head,*stu;
    int n;
    scanf("%d",&n);
    head=creat(n);
    print(head);
    head=sort(head);
    print(head);
}
