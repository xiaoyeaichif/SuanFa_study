#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int N = 10010;//边界大小
static int start_x, start_y;//出发点以及重点
static vector<int>dist(N, INT_MAX / 2);//记录初始值到点(i,j)的距离
static int n, m;//输入大小

bool st[N];//记录已经访问的元素和阻塞的元素
static vector<int>g[N];//邻接表的建立
static int Father[N];//记录父节点
static int bfs()
{
	queue<int>que;
	que.push(0);
	//记录距离刚好
	dist[0] = 0;
	st[0] = true;
	//接下来类似于二叉树的层序遍历
	while (!que.empty())//只要队列非空，就继续遍历
	{
		int size = que.size();
		while (size--)
		{
			int res = que.front();
			que.pop();
			//记录到达叶子节点的最小距离
			if (g[res].size() == 1)
			{
				return res;
			}
			for (int& x : g[res])
			{
				if (st[x] == true) continue;//提供了一种方案跳过给定的值
				Father[x] = res;//记录当前节点的父节点
				if (dist[x] > dist[res] + 1)
				{
					dist[x] = dist[res] + 1;
					que.push(x);
				}
				st[x] = true;
			}
		}
	}
	return -1;
}


int main_bfs04()
{
	//输入节点个数以及给定的步数
	cin >> n >> m;

	//建立邻接表
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int q;
	cin >> q;
	while (q--)
	{
		int c;
		cin >> c;
		st[c] = true;
	}
	int ans = bfs();
	//输出最小的深度以及对应的i
	for (int i = 0; i < n; i++)
	{
		cout << dist[i] << ' ';
	}
	cout << endl;
	return 0;
}