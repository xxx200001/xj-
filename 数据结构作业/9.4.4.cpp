//已知线性表中的元素以data值递增的次序排列，并以单链表做存储结构。
//试写一高效算法，删除表中所有值大于mink且小于maxk的元素（若表中存在这样的元素），同时释放被删结点空间，并分析该算法的时间复杂度。
//(注意，mink和maxk是给定的两个参数，它们的值可以跟表中的元素相同，也可以不同)
#include <iostream>
using namespace std;
 
#define OK 1
#define ERROR 0
 
typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /* 定义LinkList */

/* 初始化链式线性表 */
Status InitList(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if(!(*L)) /* 存储分配失败 */
            return ERROR;
    (*L)->next=NULL; /* 指针域为空 *///表示空表

    return OK;
}

Status DisplayList(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return OK;
}

Status CreateList(LinkList &L, int e)
{   // 创建单链表 L
    LinkList p = L;
    while(p->next)
        p = p->next;
    LinkList temp = (LinkList)malloc(sizeof(Node));
    temp->data = e;
    temp->next = NULL;
    p->next = temp;
 
    return OK;
}
Status DeleteMiddleElem(LinkList &L, int mink, int maxk)
{   
    // 删除单链表中大于 mink 到小于 maxk 之间的数据元素
    LinkList p, q, pre=NULL;
    if(mink > maxk) return ERROR;      // mink，maxk 大小不合法，直接返回错误

    p = L;          // p 指向头结点
    pre = p;       // pre 指向头结点
    p = p->next;  // 保证 pre 指向 p 的直接前驱节点
 
    while(p && p->data < maxk)          // 只需要遍历从首元结点到 data 域为 maxk 节点的数据元素
    {
        if(p->data <= mink)       // data 域小于等于 mink
        {
            pre = p;              // pre 指向第 1 个 data 域 大于等于 mink 的节点
            p = p->next;            // p 指向第 1 个 data 域 大于 mink 的节点
         } 
        else                      // data 域大于 mink  
        { 
            pre->next = p->next;       // pre(指向 mink)指向 p 的直接后继节点
            q = p;                      // q 指向 p 节点，因为要释放 p 节点
            p = p->next;              // p 继续指向 p 的直接后继节点
            free(q);             // 释放内存空间
        }
    }
 
    return OK;
 
}// 时间复杂度为 \(O(n)\)，只需要遍历一次链表

int main()
{
    int i;
    LinkList L;
 
    InitList(&L);
 
    for(i=1;i<=10; i++)
        CreateList(L, i);
    
    DisplayList(L);
 
    DeleteMiddleElem(L, 0, 4.5);
 
    printf("\n");
    DisplayList(L);
 
    return OK;
}