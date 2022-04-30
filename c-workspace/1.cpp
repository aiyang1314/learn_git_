#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 100
#define INCREMENT 10
typedef struct student
{
    char sid[20];
    char sname[20];
    char sex[10];
    char tel[20];
    char qq[20];
} ElemType;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} Sqlist;
//初始化
void InitList(Sqlist &L)
{
    L.elem = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
    {
        exit(-1);
    }
    L.length = 0;
    L.listsize = INIT_SIZE;
}
//顺序表插入操作
int ListInsert(Sqlist &L, int i, ElemType e)
{
    ElemType *newbase, *q, *p;
    if (i < 1 || i > L.length + 1)
    {
        return 0;
    }
    if (L.length >= L.listsize)
    {
        if (!(newbase = (ElemType *)realloc(L.elem, (L.listsize + INCREMENT) * sizeof(ElemType))))
        {
            exit(-1);
        }
        L.elem = newbase;
        L.listsize += INCREMENT;
    }
    q = L.elem + i - 1;
    for (p = L.elem + L.length - 1; p >= q; p--)
    {
        *(p + 1) = *p;
    }
    *q = e;
    ++L.length;
    return 1;
}
//输入函数
void input(ElemType *s)
{
    printf("请输入学号:");
    scanf("%s", s->sid);
    printf("请输入姓名:");
    scanf("%s", *s->sname);
    printf("请输入性别:");
    scanf("%s", s->sex);
    printf("请输入手机号码:");
    scanf("%s", s->tel);
    printf("请输入qq:");
    scanf("%s", s->qq);
}
void output(ElemType s)
{
    printf("%s\t", s.sid);
    printf("%s\t", s.sname);
    printf("%d\t", s.sex);
    printf("%s\t", s.tel);
    printf("%s\t", s.qq);
}
void ListTraverse(Sqlist L, void (*vi)(ElemType))
{
    ElemType *p;
    int i;
    p = L.elem;
    for (i = 1; i <= L.length; i++)
    {
        vi(*p++);
        printf("\n");
    }
}
ElemType getBysid(Sqlist L, int a)
{
    printf("%d", a);
    ElemType *p;
    p = L.elem;
    int i = 0;
    printf("p的值%d\n", *(p->sid));
    while (i < L.length)
    {
        if (*(p->sid) == a)
        {
            return *p;
        }
        else
        {
            // p++;
            // i++;
            return *p;
        }
    }
}
//删除操作
int ListDelete(Sqlist &L, int i, ElemType &e)
{
    ElemType *p, *q;
    if (i < 1 || i > L.length)
    {
        return 0;
    }
    p = L.elem + i - 1;
    e = *p;
    q = L.elem + L.length - 1;
    for (++p; p <= q; ++p)
        *(p - 1) = *p;
    L.length--;
    return 1;
}
int main()
{
    Sqlist L;
    int i, j, k;
    ElemType e, f;
    ElemType array[6] = {
        {"2013001", "张珊", "女", "13800001919", "34578"},
        {"2013002", "李思", "女", "13910121978", "8796532"},
        {"2013003", "陈琪", "女", "13789450012", "3789123"},
        {"2013004", "王强", "男", "13534408976", "6543783"},
        {"2013005", "赵括", "男", "13634567856", "5679"},
        {"2013006", "刘刚", "男", "13386543211", "98315"}

    };
    InitList(L);
    for (j = 0; j < 2; j++)
    {
        ListInsert(L, j + 1, array[j]);
    }
    printf("表元素:\n");
    printf("学号\t姓名\t性别\t手机号码\tqq号\n");
    ListTraverse(L, output);
    printf("\n");
    for (i = j; i < 6; i++)
    {
        ListInsert(L, i + 1, array[i]);
    }
    printf("新表元素\n");
    printf("学号\t姓名\t性别\t手机号码\tqq号\n");
    ListTraverse(L, output);
    //根据学号查找
    ElemType m = getBysid(L, 2013002);
    printf("学号为2013001的信息为:\n");
    output(m);
    printf("\n");
    //删除第1个元素
    k = ListDelete(L, 1, e);
    if (k == -1)
    {
        printf("删除失败");
    }
    else
    {
        printf("删除的数据为：");
        output(e);
    }
    printf("删除后新表为：\n");
    printf("学号\t姓名\t性别\t手机号码\tqq号\n");
    ListTraverse(L, output);
}