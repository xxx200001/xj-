#include <iostream>
using namespace std;

#define MAXSIZE 10
#define ElemType int

typedef struct
{
    ElemType data[MAXSIZE];
    int top; // 栈顶指针
} SqStack; // 顺序栈

// 初始化栈
void InitStack(SqStack &S)
{
    S.top = -1;
}

// 出栈
bool Pop(SqStack &S, ElemType &x)
{
    if (S.top == -1)
        return false; // 栈空
    x = S.data[S.top--];
    return true;
}

// 入栈
bool Push(SqStack &S, ElemType x)
{
    if (S.top == MAXSIZE - 1)
        return false; // 栈满
    S.data[++S.top] = x;
    return true;
}

// 获取栈顶元素
bool GetTop(SqStack S, ElemType &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

// 删除栈中所有值为m的元素
void DeleteAllM(SqStack &S, ElemType m)
{
    SqStack temp; // 辅助栈：暂存不需要删除的元素
    InitStack(temp);
    ElemType x;

    // 步骤1：将原栈元素弹出，筛选后放入辅助栈
    while (Pop(S, x)) // 弹出原栈所有元素
    {
        if (x != m) Push(temp, x);// 若元素不等于m，则压入辅助栈
        
        // 若元素等于m，则直接丢弃（不压入辅助栈，即被删除）
    }

    // 步骤2：将辅助栈元素弹回原栈，恢复栈结构
    while (Pop(temp, x))
    {
        Push(S, x);
    }
}

// 打印栈中元素（从栈顶到栈底）
void PrintStack(SqStack S)
{
    SqStack temp; // 临时栈：用于恢复原栈
    InitStack(temp);
    ElemType x;

    cout << "栈元素（栈顶->栈底）：";
    while (Pop(S, x))
    {
        cout << x << " ";
        Push(temp, x); // 暂存到临时栈
    }
    cout << endl;

    // 恢复原栈（将临时栈元素弹回原栈）
    while (Pop(temp, x))
    {
        Push(S, x);
    }
}

int main()
{
    SqStack S;
    InitStack(S);

    // 向栈中压入元素：1, 3, 2, 3, 4（栈顶为4）
    Push(S, 1);
    Push(S, 3);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);

    cout << "删除前：";
    PrintStack(S);

    ElemType m = 3;
    DeleteAllM(S, m); // 删除所有值为3的元素

    cout << "删除值为" << m << "后：";
    PrintStack(S);

    return 0;
}