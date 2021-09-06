// 给定一个按照升序排列的长度为n的整数数组，以及 q 个查询。

// 对于每个查询，返回一个元素k的起始位置和终止位置（位置从0开始计数）。

// 如果数组中不存在该元素，则返回“-1 -1”。

#include <iostream>
using namespace std;
int main () {
    int n , m; cin >> n >> m;
    int q[n];
    for (int i = 0 ; i < n ; i ++) cin >> q[i];
    while (m --) {
        int a; cin >> a;
        int l = 0 , r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;       //下取整 就是找左端点的
            if (q[mid] >= a) r = mid ;
            else l = mid + 1;
        }
        
        if (q[l] != a) {
            cout << "-1 -1\n";
            continue;
        }
        else cout << l << " ";
        l = 0 , r = n - 1;
        while (l < r) {         // 上取整 找右端点
            int mid = l + r + 1 >> 1;
            if (q[mid] <= a) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
    return 0;
}