#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int N = 1e5+10;//�߽��С
static int start_x, start_y;//�������Լ��ص�
static vector<long long>dist(N, LLONG_MAX / 2);//��¼��ʼֵ����(i,j)�ľ���
static int n;//�����С
static long long m;

static vector<int>g[N];//�ڽӱ�Ľ���
static vector<int>a(N);

static void bfs()
{
	queue<int>que;
	que.push(1);
	//��¼����պ�
	dist[1] = 0;
	//�����������ڶ������Ĳ������
	while (!que.empty())//ֻҪ���зǿգ��ͼ�������
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
	//����ڵ�����Լ������Ĳ���
	cin >> n >> m ;
	//��������ֵ
	/*for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}*/
	//�����ڽӱ�
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
			cout << i << " �� " << dist[i] << endl;
		}
	}
	return 0;
}