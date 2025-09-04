#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // 防止整数溢出
        
        if (arr[mid] == target) {
            return mid; // 找到目标，返回索引
        } else if (arr[mid] < target) {
            low = mid + 1; // 搜索右半部分
        } else {
            high = mid - 1; // 搜索左半部分
        }
    }
    
    return -1; // 未找到目标
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7;
    
    int result = binarySearch(arr, target);
    
    if (result != -1) {
        cout << "元素 " << target << " 在索引 " << result << " 处找到" << endl;
    } else {
        cout << "元素 " << target << " 未找到" << endl;
    }
    
    return 0;
}