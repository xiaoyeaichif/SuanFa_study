#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int N = 10010;//�߽��С
static int start_x, start_y;//�������Լ��ص�
static vector<int>dist(N, INT_MAX / 2);//��¼��ʼֵ����(i,j)�ľ���
static int n, m;//�����С

bool st[N];//��¼�Ѿ����ʵ�Ԫ�غ�������Ԫ��
static vector<int>g[N];//�ڽӱ�Ľ���
static int Father[N];//��¼���ڵ�
static int bfs()
{
	queue<int>que;
	que.push(0);
	//��¼����պ�
	dist[0] = 0;
	st[0] = true;
	//�����������ڶ������Ĳ������
	while (!que.empty())//ֻҪ���зǿգ��ͼ�������
	{
		int size = que.size();
		while (size--)
		{
			int res = que.front();
			que.pop();
			//��¼����Ҷ�ӽڵ����С����
			if (g[res].size() == 1)
			{
				return res;
			}
			for (int& x : g[res])
			{
				if (st[x] == true) continue;//�ṩ��һ�ַ�������������ֵ
				Father[x] = res;//��¼��ǰ�ڵ�ĸ��ڵ�
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
	//����ڵ�����Լ������Ĳ���
	cin >> n >> m;

	//�����ڽӱ�
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
	//�����С������Լ���Ӧ��i
	for (int i = 0; i < n; i++)
	{
		cout << dist[i] << ' ';
	}
	cout << endl;
	return 0;
}