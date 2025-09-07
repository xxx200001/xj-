//head指向一单链表，请编写算法在单链表中每个data域为S的结点前插入一个data域为T的新结点。
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *insert(Node *head, int S, int T)
{
    Node *p = head;
    Node *pre = NULL; // 记录当前节点的前驱节点
    while (p != NULL)
    {
        if (p->data == S)
        {
           // 创建新节点
            Node *q = new Node;
            q->data = T;
            q->next = p; // 新节点的next指向当前节点p（关键：插到p前面）
            if (pre == NULL)  head = q;// 特殊情况：p是头节点，新节点成为新的头节点     
            else
            { // 普通情况：前驱节点的next指向新节点
                pre->next = q;}
            // 插入后，prev需要更新为新节点（因为下一轮p还是当前的S节点，避免重复插入）
            pre = q;
        }
        else
        {
            // 不匹配时，前驱节点正常后移
            pre = p;
        }
        // 当前节点后移，继续遍历
        p = p->next;
    }
    return head;
}
int main()
{
    int arr[] = {1, 3,2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = new Node{arr[0], NULL};
    Node *tail = head;
    for (int i = 1; i < n; i++)
    {
        tail->next = new Node{arr[i], NULL};
        tail = tail->next;
    }

    cout << "原始链表: ";
    Node *p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    int S = 3, T = 9999;
    head = insert(head, S, T);

    cout << "新链表: ";
    p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    // Free memory
    p = head;
    while (p)
    {
        Node *temp = p;
        p = p->next;
        delete temp;
    }

    return 0;
}