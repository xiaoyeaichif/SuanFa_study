
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 最短路径问题,结合bfs解决

static const int N = 1005;
static vector<vector<int>>nums(N, vector<int>(N, 0));
// 距离数组,无穷大标记无法到达
static vector<vector<int>>dist(N, vector<int>(N, INT_MAX));
// 方向数组
static int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

// 输入坐标
static int start_x, start_y;
static int end_x, end_y;
static int k;

// 行和列
static int n, m;

struct node
{
    int x, y;
    int tot;
};



// bfs逻辑
static int bfs()
{
    queue<pair<int, int>>que;
    if (nums[start_x][start_y] == 1 || nums[end_x][end_y] == 1)
    {
        return -1;
    }
    que.push({ start_x,start_y });
    dist[start_x][start_y] = 0;
    // 开始检测
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            auto node = que.front();
            que.pop();
            // 如果已经到达终点，立即返回结果
            if (node.first == end_x && node.second == end_y) {
                return dist[end_x][end_y];
            }
            // 开始遍历每个方向
            for (int k = 0; k < 4; k++)
            {
                int next_x = dx[k] + node.first;
                int next_y = dy[k] + node.second;
                // 有些点是需要跳过的---》边界条件
                if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
                {
                    continue;
                }
                // 只要是非0，代表该点已经遍历过了
                if (nums[next_x][next_y] != 0)
                {
                    continue;
                }
                if (dist[next_x][next_y] > dist[node.first][node.second] + 1)
                {
                    dist[next_x][next_y] = dist[node.first][node.second] + 1;
                    que.push({ next_x,next_y });
                    // 等于0代表是可以访问的
                    // 访问过了，接下来不可以访问
                    nums[next_x][next_y] = 1;
                }
            }
        }
    }
    return dist[end_x][end_y] == INT_MAX ? -1 : dist[end_x][end_y];
}

int main_101010()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> start_x >> start_y;
	cin >> end_x >> end_y;
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		// 这两个点到达不了
		nums[x][y] = 1e9;
	}
	// bfs
	queue<node>que;
	que.push({ start_x,start_y, 0 });
	while (!que.empty())
	{
		node p = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}
			if (nums[nx][ny] != 0 || (nx == start_x && ny == start_y))
			{
				continue;
			}
            // 更新距离
			nums[nx][ny] = p.tot + 1;
            // 能够移动到该节点，表示已经找到就是最短距离，直接返回
			if (nx == end_x && ny == end_y)
			{
				cout << nums[nx][ny];
				return 0;
			}
            // 将遍历到的继续放进队列中
			que.push({ nx,ny,p.tot + 1 });
		}
	}
	cout << -1;
	return 0;
}




