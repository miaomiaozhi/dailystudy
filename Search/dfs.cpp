// 给定一个整数n，将数字1~n排成一排，将会有很多种排列方法。

// 现在，请你按照字典序将所有的排列方法输出。

#include <iostream>
using namespace std;
int n ;
const int N = 1e5 + 10;
int times[N] = {0};
int path[N] = {0};
void dfs (int l) {
    if (l == n) {
        for (int i = 0 ; i < n ; i ++) {
            if (i != 0) cout << " ";
            cout << path[i];
        }
        cout << endl;
        return ;
    }
    for (int i = 1 ; i <= n; i ++) {
        if (times[i] == 0) {
            path[l] = i;
            times[i] = 1;
            dfs(l + 1);     //进入下一层
            times[i] = 0;
        }
    }
}
int main () {
    cin >> n;
    dfs (0);
    return 0;
}