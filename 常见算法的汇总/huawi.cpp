
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//static const int N = 1010;
//static vector<vector<int>>nums(N);
//vector<vector<int>>dist(N, vector<int>(N,INT_MAX));
//
static int n, m, k;
static int sx, sy, ex, ey;
static int a[1010][1010];
static int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

struct node {
	int x, y;
	int tot;
};
//
//static void bfs()
//{
//    queue<pair<int, int>>que;
//    que.push({ start_x,start_y });
//    dist[start_x][start_y] = 0;
//
//    // bfs组合逻辑
//    while (!que.empty())
//    {
//        int size = que.size();
//        while (size--)
//        {
//            auto node = que.front();
//            que.pop();
//            for (int i = 0; i < 4; i++)
//            {
//                int next_x = dx[i] + node.first;
//                int next_y = dy[i] + node.second;
//                if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
//                {
//                    continue;
//                }
//                if (dist[next_x][next_y] == -1) continue;
//                if (dist[next_x][next_y] > dist[node.first][node.second] + 1)
//                {
//                    dist[next_x][next_y] = dist[node.first][node.second] + 1;
//                    que.push({ next_x ,next_y });
//                }
//            }
//        }
//    }
//}

int main_101010()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> sx >> sy;
	cin >> ex >> ey;
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		// 这两个点到达不了
		a[x][y] = 1e9;
	}
	// bfs
	queue<node>que;
	que.push((node){ sx, sy, 0 });
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
			if (a[nx][ny] != 0 || (nx == sx && ny == sy))
			{
				continue;
			}
			a[nx][ny] = p.tot + 1;
			if (nx == ex && ny == ey)
			{
				cout << a[nx][ny];
				return 0;
			}
			que.push((node){ nx,ny,p.tot + 1 });
		}
	}
	cout << -1;
	return 0;
}




