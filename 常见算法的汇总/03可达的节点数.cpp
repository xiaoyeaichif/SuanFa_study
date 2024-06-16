#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int N = 1e5+10;//边界大小
static int start_x, start_y;//出发点以及重点
static vector<long long>dist(N, LLONG_MAX / 2);//记录初始值到点(i,j)的距离
static int n;//输入大小
static long long m;

static vector<int>g[N];//邻接表的建立
static vector<int>a(N);

static void bfs()
{
	queue<int>que;
	que.push(1);
	//记录距离刚好
	dist[1] = 0;
	//接下来类似于二叉树的层序遍历
	while (!que.empty())//只要队列非空，就继续遍历
	{
		int res = que.front();
		que.pop();
		for (int& x : g[res])
		{
			if (dist[x] > dist[res] + 1)
			{
				dist[x] = dist[res] + 1;
				que.push(x);
			}
		}
	}
}


int main_bfs03()
{
	//输入节点个数以及给定的步数
	cin >> n >> m ;
	//建立数组值
	/*for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}*/
	//建立邻接表
	for (int i = 1; i <= n; i++)
	{
		int b;
		cin >> b;
		g[i].push_back(b);
	}
	bfs();
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] <= m)
		{
			cout << i << " ： " << dist[i] << endl;
		}
	}
	return 0;
}