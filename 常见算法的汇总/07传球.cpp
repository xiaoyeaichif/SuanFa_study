

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int N = 1010;
static int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
static vector<vector<int>>nums(N, vector<int>(N, 0));
static vector<vector<int>>dist(N, vector<int>(N, INT_MAX));
static int n, m;

static void bfs()
{
    queue<pair<int, int>>que;
    for (int i = 0; i < n; i++)
    {
        if (nums[i][0] == 1)
        {
            que.push({ i,0 });
            dist[i][0] = 0;
        }
    }
    // 开始遍历队列
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            auto node = que.front();
            que.pop();
            int x1 = node.first;
            int y1 = node.second;
            // 遍历周围的点
            for (int i = 0; i < 4; i++)
            {
                int next_x = x1 + dx[i];
                int next_y = y1 + dy[i];
                // 只找能走的
                if (next_x >= 0 && next_x < n && next_y >= 0 &&
                    next_y < m && dist[next_x][next_y] == INT_MAX
                    && nums[next_x][next_y] == 1)
                {
                    dist[next_x][next_y] = dist[x1][y1] + 1;
                    que.push({ next_x,next_y });
                }
            }
        }

    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
}

// 寻找最小值
int getMin()
{
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dist[i][m - 1]);
    }
    return ans == INT_MAX ? -1 : ans;
}

int main_07()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }
    bfs();
    cout << getMin() << endl;
    return 0;
}