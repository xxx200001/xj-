//递归法实现链表的反转
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *reverse(Node *pre, Node *cur)
{
    if (!cur)return pre; 
    // 如果 cur 为 NULL，说明原链表已经全部处理完。
    //当 cur == NULL 时，pre 指向新的链表头（原链表的尾）。返回它作为最终结果。

    Node *temp=cur->next;
    //将当前节点 cur 的 next 指向 pre，即把当前节点加入到已反转部分的前端（完成一次反转指向）。

    cur->next=pre;
    //将当前节点 cur 的 next 指向 pre，即把当前节点加入到已反转部分的前端（完成一次反转指向）。
   
    //将cur作为pre传入下一层
    //将temp作为cur传入下一层，改变其指针指向当前cur

    return reverse(cur,temp);
    //递归调用，继续处理下一个节点，同时把已经处理好的部分头设为新的 pre（即当前节点 cur）。


}

   
// 反转链表入口函数
Node *reverseList(Node *head)
{
    return reverse(NULL, head);// 初始pre为nullptr，cur为头节点
}

// 创建链表（尾插法）
Node* createList(int arr[], int n)
{
    if (n <= 0) return nullptr;
    
    Node *head = new Node{arr[0], nullptr};
    Node *tail = head;
    
    for (int i = 1; i < n; i++)
    {
        tail->next = new Node{arr[i], nullptr};
        tail = tail->next;
    }
    return head;
}

// 打印链表
void printList(Node *head)
{
    Node *p = head;
    while (p)
    {
        cout << p->data;
        if (p->next) cout << " -> ";
        p = p->next;
    }
    cout << endl;
}

// 释放链表内存
void freeList(Node *head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    // 创建示例链表：1 -> 2 -> 3 -> 4 -> 5
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = createList(arr, n);
    
    cout << "原链表：";
    printList(head);
    
    // 反转链表
    Node *reversedHead = reverseList(head);
    
    cout << "反转后：";
    printList(reversedHead);
    
    // 释放内存
    freeList(reversedHead);
    return 0;
}
