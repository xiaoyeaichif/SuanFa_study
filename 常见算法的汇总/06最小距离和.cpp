#include<iostream>
#include<queue>
#include<vector>


using namespace std;

const int N = 1010;
static vector<vector<int>>dist(N, vector<int>(N, INT_MAX)); //初始化距离为最大值
static vector<vector<int>>nums(N, vector<int>(N, 0));
static int n, m;
static int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

//
int solve() {
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (nums[i][j] == 1 && dist[i][j] != INT_MAX) {
				ans += dist[i][j];
			}
		}
		cout << endl;
	}
	return ans;
}


// 多源bfs
static void bfs()
{
	queue<pair<int, int>>que;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (nums[i][j] == 0)
			{
				que.push({ i,j });
				 // 表示初始位置为0
				dist[i][j] = 0;
			}
		}
	}

	// 层序遍历的过程
	while (!que.empty())
	{
		auto node = que.front();
		que.pop();
		int x1 = node.first;
		int y1 = node.second;
		// 遍历四周
		for (int i = 0; i < 4; i++)
		{
			int next_x = x1 + dx[i];
			int next_y = y1 + dy[i];
			// 只有一种情形才会继续遍历
			// 那就是当前的坐标不是 -1 时候
			if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n
				&& dist[next_x][next_y] == INT_MAX && nums[next_x][next_y] != -1)
			{
				dist[next_x][next_y] = dist[x1][y1] + 1;
				que.push({ next_x,next_y });
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
}

int main_bfs06()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nums[i][j];
		}
	}
	bfs();
	cout << solve() << endl;
	return 0;
}