#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int N = 410;//边界大小
static int start_x, start_y;//出发点以及重点
static vector<vector<int>>dist(N, vector<int>(N, INT_MAX / 2));//记录初始值到点(i,j)的距离
static vector<vector<char>>nums(N, vector<char>(N));//输入数组
static int n,m;//输入大小
//代表合理的点
struct node {
	int x;
	int y;
};

static int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
static int dy[8] = { -1,1,-2,2,-2,2,-1,1 };

static void bfs()
{
	queue<node>que;
	que.push({ start_x,start_y });
	//记录距离刚好
	dist[start_x][start_y] = 0;
	//接下来类似于二叉树的层序遍历
	while (!que.empty())//只要队列非空，就继续遍历
	{
		node res = que.front();
		int x = res.x, y = res.y;
		que.pop();
		for (int i = 0; i < 8; i++)
		{
			int a = x + dx[i];
			int b = y + dy[i];
			if (a < 1 || b < 1 || a > n || b > n)
			{
				continue;
			}
			//更新值
			if (dist[a][b] > dist[x][y] + 1)
			{
				dist[a][b] = dist[x][y] + 1;
				que.push({ a,b });//加入{a,b}组成的坐标
			}
		}
	}
}


int main_bfs02()
{
	//输入初始位置和目标位置
	cin >> n >> m >> start_x >> start_y;
	bfs();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dist[i][j] == INT_MAX / 2)
			{
				cout << -1 << ' ';
			}
			else {
				cout << dist[i][j] << ' ';
			}
			
		}
		cout << endl;
	}
	return 0;
}