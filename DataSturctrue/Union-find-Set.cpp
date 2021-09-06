#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

//cnt 代表一个集合中一共有多少个节点 并且规定只有根节点的cnt才有意义
int p[N], cnt[N];

int find (int x) {      //路径压缩的find 直接找到x的根节点

    /*
    找节点操作等价于这样
    这样最后能找到根节点 但是没有路径压缩优化
    while (parent[x] != x) x = parent[x];

    一定要路径压缩 不然可能相差了几十倍的速度
    */
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b) {  //合并操作 把a的根节点插入到b的根节点
    /*在合并的时候维护连通块中的点的数量
    if (find(a) != find(b)) cnt[find(b)] += cnt[find(a)]    假如两个点不在一个集合那就将点累加
    */

    
    p[find(a)] = find(b);
}

