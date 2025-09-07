#include <iostream>
#include <cstdlib>
using namespace std;
void DeleteItem(int A[], int *n, int item) {
    int k = 0; // 新数组的下标
    for (int i = 0; i < *n; i++) {
        if (A[i] != item) {
            A[k++] = A[i];  // 覆盖
        }
    }
    *n = k;  // 更新长度
}
//顺序存储结构删除元素：通常需要移动后续元素，效率低下（每次删除都要移动一段数组）。
//更高效的方法是遍历数组，把不等于 item 的元素往前覆盖。
//定义一个新下标 k，初始为0。
//遍历数组，当 A[i] != item 时，把 A[i] 复制到 A[k]，然后 k++。
//遍历结束后，新的逻辑长度就是 k。
//这种方法时间复杂度 O(n)，只需要一次扫描，不会频繁移动。
int main() {
    int A[] = {1, 2, 3, 2, 4, 2, 5};
    int n = sizeof(A) / sizeof(A[0]);
    int item = 2;

    DeleteItem(A, &n, item);

    std::cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}