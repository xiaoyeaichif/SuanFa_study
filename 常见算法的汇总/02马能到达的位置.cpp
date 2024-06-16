#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int N = 410;//�߽��С
static int start_x, start_y;//�������Լ��ص�
static vector<vector<int>>dist(N, vector<int>(N, INT_MAX / 2));//��¼��ʼֵ����(i,j)�ľ���
static vector<vector<char>>nums(N, vector<char>(N));//��������
static int n,m;//�����С
//�������ĵ�
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
	//��¼����պ�
	dist[start_x][start_y] = 0;
	//�����������ڶ������Ĳ������
	while (!que.empty())//ֻҪ���зǿգ��ͼ�������
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
			//����ֵ
			if (dist[a][b] > dist[x][y] + 1)
			{
				dist[a][b] = dist[x][y] + 1;
				que.push({ a,b });//����{a,b}��ɵ�����
			}
		}
	}
}


int main_bfs02()
{
	//�����ʼλ�ú�Ŀ��λ��
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