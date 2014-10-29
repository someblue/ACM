#include "stdio.h"
#include "malloc.h"
#include "string.h"
typedef struct
{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
} HTNode,*HuffmanTree;
typedef char **HuffmanCode;
void   Select(HuffmanTree &HT, int n, int &s1, int &s2)
//��HT[1..n]��ѡ��parentΪ0��weight��С��������㣬
// ����ŷֱ�Ϊs1��s2��
{
    int i;
    s1=-1;
    s2=-1;
    for (i=1; i<=n; i++)
    {
        if (HT[i].parent==0)
        {
            if (s1==-1) s1=i;
            else if (s2==-1 )
                if (HT[i].weight>=HT[s1].weight) s2=i;
                else s2=s1,s1=i;
            else if(HT[i].weight<HT[s1].weight) s2=s1,s1=i;
            else if(HT[i].weight<HT[s2].weight) s2=i;
        }
    }
}
// �����n���ַ��Ĺ���������HC
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
    int i, j, m, s1, s2, start;
    char *cd;
    unsigned int c, f;
    if (n<=1) return;
    m = 2 * n - 1;
    HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));  // 0�ŵ�Ԫδ��
    for (i=1; i<=n; i++)   //��ʼ��
    {
        HT[i].weight=w[i-1];
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for (i=n+1; i<=m; i++)   //��ʼ��
    {
        HT[i].weight=0;
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
//    printf("\n���������Ĺ������������ʾ��\n");
//    printf("HT��̬:\n  ���  weight  parent  lchild  rchild");
//    for (i=1; i<=m; i++)
//        printf("\n%4d%8d%8d%8d%8d",i,HT[i].weight,
//               HT[i].parent,HT[i].lchild, HT[i].rchild);
//    printf("    ������������� ...\n");
//    getch();
    for (i=n+1; i<=m; i++)    // ����������
    {
        // ��HT[1..i-1]��ѡ��parentΪ0��weight��С��������㣬
        // ����ŷֱ�Ϊs1��s2��
        Select(HT, i-1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
//        printf("\nselect: s1=%d   s2=%d\n", s1, s2);
//        printf("  ���  weight  parent  lchild  rchild");
//        for (j=1; j<=i; j++)
//            printf("\n%4d%8d%8d%8d%8d",j,HT[j].weight,HT[j].parent,HT[j].lchild, HT[j].rchild);
//        printf("    ������������� ...\n");
//        getch();
    }
    //--- ��Ҷ�ӵ���������ÿ���ַ��Ĺ��������� ---
    cd = (char *)malloc(n*sizeof(char));    // ���������Ĺ����ռ�
    cd[n-1] = '\0';                         // �����������
    for (i=1; i<=n; ++i)                    // ����ַ������������
    {
        start = n-1;                          // ���������λ��
        for (c=i, f=HT[i].parent; f!=0; c=f, f=HT[f].parent)
            // ��Ҷ�ӵ������������
            if (HT[f].lchild==c) cd[--start] = '0';
            else cd[--start] = '1';
        HC[i] = (char *)malloc((n-start)*sizeof(char));
        // Ϊ��i���ַ��������ռ�
        strcpy(HC[i], &cd[start]);    // ��cd���Ʊ���(��)��HC

    }
    free(cd);   //�ͷŹ����ռ�
} //HuffmanCoding

int main()
{
    int i,n;
    int *w;
    HuffmanTree HT;
    HuffmanCode HC;
//    printf("Node Number:");
    scanf("%d",&n);  //Ȩֵ����
    w=(int *)malloc(n*sizeof(int));
//    printf("Input weights:");
    for ( i=0; i<n; i++) //¼��Ȩֵ
        scanf("%d",&w[i]);

    HC=(char **)malloc((n+1)*sizeof(char*)); //0�ռ�δ��
    HT=(HuffmanTree)malloc((2*n+1+1)*sizeof(HTNode));//0�ռ�δ��
    HuffmanCoding(HT, HC, w, n);
//    printf("\n");
    for (i = 1; i<n+1; i++)
    {
        puts(HC[i]);  //�������������
        free(HC[i]);  //�ͷſռ�
    }
    free(HC);
    free(HT);
}//main
