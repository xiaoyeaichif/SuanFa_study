#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int N = 1010;//�߽��С
static int start_x, start_y, end_x, end_y;//�������Լ��ص�
static vector<vector<int>>dist(N, vector<int>(N, INT_MAX/2));//��¼��ʼֵ����(i,j)�ľ���
static vector<vector<char>>nums(N, vector<char>(N));//��������
static int n;//�����С
//�������ĵ�
struct node {
	int x;
	int y;
};

static int dx[4] = { -1,1,0,0 };
static int dy[4] = { 0,0,-1,1 };

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
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i];
			int b = y + dy[i];
			if (a < 1 || b < 1 || a > n || b > n)
			{
				continue;
			}
			if (nums[a][b] == '1 ') continue;//ֻҪ���ַ�1Ҳ����
			//����ֵ
			if (dist[a][b] > dist[x][y] + 1)
			{
				dist[a][b] = dist[x][y] + 1;
				que.push({ a,b });//����{a,b}��ɵ�����
			}
		}
	}
	//int ans = dist[end_x][end_y] == INT_MAX ? -1 : dist[end_x][end_y];
}


int main_bfs01()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> nums[i][j];
		}
	}
	//�����ʼλ�ú�Ŀ��λ��
	cin >> start_x >> start_y >> end_x >> end_y;
	bfs();
	int ans = dist[end_x][end_y] == INT_MAX /2? -1 : dist[end_x][end_y];
	cout << ans << endl;
	return 0;
}