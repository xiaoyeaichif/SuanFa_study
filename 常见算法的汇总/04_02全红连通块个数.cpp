#include <iostream>
#include <vector>
#include <algorithm> // ���� std::fill
using namespace std;

// ʹ�� vector �����������
static vector<vector<bool>> visited;
static vector<vector<char>> grid;
static int n, m;
static int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

static void dfs(int x, int y) {
    visited[x][y] = true; // ��� (x, y) Ϊ�ѷ���
    for (int i = 0; i < 4; i++) { // ���� (x, y) ��Χ�ĸ�����
        int a = x + dx[i];
        int b = y + dy[i];
        // �ж��Ƿ�Խ��
        if (a < 0 || b < 0 || a >= n || b >= m) continue;
        // ��ǰԪ���ѱ����ʻ��ǰ�ɫ
        if (visited[a][b] || grid[a][b] == 'W') continue;
        // ��������
        dfs(a, b);
    }
}

// ��ȡ��ɫ������ͨ��ĸ���
int get_red_component_count() {
    fill(visited.begin(), visited.end(), vector<bool>(m, false)); // ��ʼ���������
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // ��ǰԪ���Ǻ�ɫ��û�б����ʹ�
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
            // ��¼��ǰԪ�ص���ɫ
            char temp = grid[i][j];
            grid[i][j] = 'W'; // ���µ�ǰԪ��Ϊ��ɫ
            result[i][j] = get_red_component_count(); // ������ͨ�����
            grid[i][j] = temp; // �ָ�ԭ������ɫ
        }
    }

    // ������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
