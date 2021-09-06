// 宽度优先搜索
// 找到迷宫中从左上角到右下角的最短距离 

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 105;
int dist[N][N], path[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};       //上下左右四个方向

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < N; i ++) {      //先把每个位置的距离设置成-1 代表着无法达到或者还未达到
        for (int j = 0; j < N; j ++) {
            dist[i][j] = -1;
        }
    }
    dist[0][0] = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> path[i][j];
        }
    }
    queue <PII> q;
    q.push({0, 0});
    while ((int)q.size()) {
        auto f = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++){
            int x = f.x + dx[i], y = f.y + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && path[x][y] == 0 && dist[x][y] == -1) {
                dist[x][y] = dist[f.x][f.y] + 1;
                q.push({x, y});
            } 
        }
    }
    cout << dist[n - 1][m - 1];
    return 0;
}