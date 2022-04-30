#include <stdio.h>
#include <stdlib.h>

typedef struct Node //单链表的存储结构，Node是结构体类型名，"stuct Node"是数据类型，如：int也是一种数据类型
{
    int data;
    struct Node *next;
} Node, *LinkList; //这里的Node是"stuct Node"类型的变量，可以和上面的-结构体类型名-重名。

struct Node *head = NULL; //头指针
struct Node *tail = NULL; //尾指针，为尾插法做准备

// int InitLinkedList(LinkList *L); //初始化,形参L是二级指针

// LinkList Head_CreatList(LinkList *L); //头插法创建单链表,创建完成后元素次序和输入时相反。引入尾插法

// LinkList Tail_CreatList(LinkList *L); //尾插法创建单链表，形参L是二级指针

// int GetElem(LinkList L, int i); //返回位序位i的结点值，头结点不存放数据，视为位置0

// int LocateElem(LinkList L, int e); //按值e查找结点位序

// int LinkListInsert(LinkList *L, int i, int e); //第i个位置插入指定元素e

// int LinkListDelete(LinkList *L, int i, int *e); //删除位序为i的结点，并用e返回其元素值

// int LinkListClear(LinkList *L); //单链表的清空操作

// int LinkListLength(LinkList L); //求单链表的长度

// int ListTraverse(LinkList L); //遍历访问整个表L
int InitLinkedList(LinkList *L) //初始化,形参L是二级指针
{
    *L = (Node *)malloc(sizeof(Node)); //头结点申请地址
    if (*L == NULL)
    {
        printf("申请空间失败\n");
        exit(0);
    }
    head = *L;         //头指针指向头结点
    tail = *L;         //尾指针指向尾结点，只初始化了1个结点，它既是头结点也是尾结点
    (*L)->data = 0;    //头结点数据域可以不存放数据，这里存放链表长度
    (*L)->next = NULL; //初始为空链表,即头结点指针指向空
    return 1;
}

LinkList Head_CreatList(LinkList *L) //头插法创建单链表,创建完成后元素次序和输入时相反。引入尾插法
{
    int x; //新插入的结点值
    printf("输入需要插入的元素值\n");
    scanf("%d", &x);
    while (x != 9999) //输入999时表示结束
    {
        LinkList s = (Node *)malloc(sizeof(Node)); //创建新结点
        s->data = x;                               //输入结点的值
        s->next = (*L)->next;
        (*L)->next = s;
        (*L)->data++; //单链表长度加一
        printf("插入成功\n");
        printf("输入需要插入的元素值(输入9999结束插入)\n");
        scanf("%d", &x);
    }
    return *L; //返回单链表地址
}

LinkList Tail_CreatList(LinkList *L) //尾插法创建单链表，形参L是二级指针
{
    int x; //新插入的结点值
    printf("输入需要插入的元素值\n");
    scanf("%d", &x);
    while (x != 9999) //输入999时表示结束
    {
        LinkList s = (Node *)malloc(sizeof(Node)); //创建新结点
        s->data = x;                               //输入结点的值
        tail->next = s;
        tail = s;     //尾指针指向新的尾结点
        (*L)->data++; //单链表长度加一
        printf("插入成功\n");
        printf("输入需要插入的元素值(输入9999结束插入)\n");
        scanf("%d", &x);
    }
    tail->next = NULL; //尾结点的指针域置空
    return *L;         //返回单链表地址
}

int GetElem(LinkList L, int i) //返回位序位i的结点值，头结点不存放数据，视为位置0
{
    int j = 1;            //从位序1开始找，跳过头结点
    LinkList p = L->next; //头接结点指针赋值给p,p指向第1个结点。头结点为第0个结点
    if (i == 0)
        return L->data;                 // i等于0就是返回头结点数值，既单链表长度，也可以存放其他信息
    if (i < 1 || i > LinkListLength(L)) //查找位置非法
        return -9999;                   //返回 -9999表示查询位序非法
    while (p && j < i)                  //从第一个结点找到第i个结点，P为NULL或j>=i时退出
    {
        p = p->next;
        j++;
    }
    return p->data;
}

int LocateElem(LinkList L, int e) //按值e查找结点位序
{
    int k = 1;
    LinkList p = L->next; // p指向第一个结点，不是头结点
    while (p && p->data != e)
    {
        p = p->next;
        k++;
    }
    if (p) // p!=NULL 表示找到，返回其位置
        return k;
    else
        return 0; //没有找到其位置返回0
}

int LinkListInsert(LinkList *L, int i, int e) //第i个位置插入指定元素e
{
    int j = 1;
    LinkList p, s;
    p = *L;
    while (p && j < i) //寻找第i-1个结点
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return 0;                     //插入位置非法
    s = (Node *)malloc(sizeof(Node)); //动态分配内存
    s->data = e;
    s->next = p->next;
    p->next = s;
    (*L)->data++; //单链表长度加一
    return 1;
}

int LinkListDelete(LinkList *L, int i, int *e) //删除位序为i的结点，并用e返回其元素值
{
    LinkList p, q;           // p指向被删除结点的前驱，q指向被删除结点
    int j = 1;               //从第一个结点开始找
    p = *L;                  // p指向头结点
    while (p->next && j < i) //遍历寻找第i-1个结点
    {
        p = p->next;
        j++;
    }
    if (!(p->next)) //若p->next=NULL,此时链表长度可能小于i
        return 0;
    q = p->next;       // q指向被删除的结点
    p->next = q->next; //将*q从链表中断开
    *e = q->data;      //将q结点中的数据传给e
    free(q);           //释放内存
    (*L)->data--;      //单链表长度减少一
    return *e;
}

int LinkListClear(LinkList *L) //单链表的清空操作
{
    LinkList p, q;
    p = (*L)->next; // p指向第一个结点，不是头结点,头结点视为第0个结点
    while (p)
    {
        q = p->next; // q指向p的下一个结点
        free(p);     //释放p;完成后第一个结点为q
        p = q;       //让p指向第一个结点，重复上面操作
    }
    (*L)->next = NULL; //头结点指针赋值NULL

    // free(*L);                                //下面两步会销毁单链表
    // head = NULL;
    (*L)->data = 0; //单链表长度置为0
    return 0;
}

int LinkListLength(LinkList L) //求单链表的长度
{
    LinkList p = L;
    int k = 0;
    while (p->next) //若p=NULL，怎遍历完成
    {
        p = p->next;
        k++;
    }
    return k;
}

int ListTraverse(LinkList L) //遍历访问整个表L
{
    Node *p;
    for (p = L->next; p != NULL; p = p->next)
        printf("%-5d", p->data);
    return 0;
}
int main()
{
    LinkList L = NULL;
    int i, e; // i是位序,e是元素值
    if (InitLinkedList(&L))
        printf("初始化成功\n");
    // Head_CreatList(&L);								//头插法初始化
    Tail_CreatList(&L); //尾插法初始化
    ListTraverse(L);    //遍历输出

    printf("\n输入需要查找的序号\n");
    scanf("%d", &i);
    printf("所查结点值为%d\n", GetElem(L, i)); //查找位序对应的元素值

    printf("\n输入需要查找的元素值\n");
    scanf("%d", &e);
    if (LocateElem(L, e))
        printf("所查结点位序为%d\n", LocateElem(L, e)); //查找元素值对应的位序
    else
        printf("查询无果\n");

    printf("输入需要插入的位序i和数值e\n");
    scanf("%d%d", &i, &e);
    if (LinkListInsert(&L, i, e)) //插入
    {
        printf("插入成功，当前元素为\n");
        ListTraverse(L);
    }
    else
        printf("插入失败\n");

    printf("\n输入需要删除的位序\n");
    scanf("%d", &i);
    LinkListDelete(&L, i, &e);
    printf("删除的结点元素值为：%d\n", e);
    printf("删除后\n");
    ListTraverse(L);                   //遍历输出
    printf("\n当前长度%d\n", L->data); //我在头结点的值域中存放了链表长度，也可以调用函数LinkListLength(L)

    LinkListClear(&L);
    printf("清空后长度为%d\n", LinkListLength(L));
    return 0;
}