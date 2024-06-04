#include <iostream>
#include <vector>
#include <algorithm> // 包含 std::fill
using namespace std;

// 使用 vector 替代定长数组
static vector<vector<bool>> visited;
static vector<vector<char>> grid;
static int n, m;
static int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

static void dfs(int x, int y) {
    visited[x][y] = true; // 标记 (x, y) 为已访问
    for (int i = 0; i < 4; i++) { // 遍历 (x, y) 周围四个方向
        int a = x + dx[i];
        int b = y + dy[i];
        // 判断是否越界
        if (a < 0 || b < 0 || a >= n || b >= m) continue;
        // 当前元素已被访问或是白色
        if (visited[a][b] || grid[a][b] == 'W') continue;
        // 继续搜索
        dfs(a, b);
    }
}

// 获取红色区域连通块的个数
int get_red_component_count() {
    fill(visited.begin(), visited.end(), vector<bool>(m, false)); // 初始化标记数组
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 当前元素是红色且没有被访问过
            if (grid[i][j] == 'R' && !visited[i][j]) {
                count++;
                dfs(i, j);
            }
        }
    }
    return count;
}

int main_0402() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> result(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 记录当前元素的颜色
            char temp = grid[i][j];
            grid[i][j] = 'W'; // 更新当前元素为白色
            result[i][j] = get_red_component_count(); // 更新连通块个数
            grid[i][j] = temp; // 恢复原来的颜色
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
