
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ���·������,���bfs���

static const int N = 1005;
static vector<vector<int>>nums(N, vector<int>(N, 0));
// ��������,��������޷�����
static vector<vector<int>>dist(N, vector<int>(N, INT_MAX));
// ��������
static int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

// ��������
static int start_x, start_y;
static int end_x, end_y;
static int k;

// �к���
static int n, m;

struct node
{
    int x, y;
    int tot;
};



// bfs�߼�
static int bfs()
{
    queue<pair<int, int>>que;
    if (nums[start_x][start_y] == 1 || nums[end_x][end_y] == 1)
    {
        return -1;
    }
    que.push({ start_x,start_y });
    dist[start_x][start_y] = 0;
    // ��ʼ���
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            auto node = que.front();
            que.pop();
            // ����Ѿ������յ㣬�������ؽ��
            if (node.first == end_x && node.second == end_y) {
                return dist[end_x][end_y];
            }
            // ��ʼ����ÿ������
            for (int k = 0; k < 4; k++)
            {
                int next_x = dx[k] + node.first;
                int next_y = dy[k] + node.second;
                // ��Щ������Ҫ������---���߽�����
                if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
                {
                    continue;
                }
                // ֻҪ�Ƿ�0������õ��Ѿ���������
                if (nums[next_x][next_y] != 0)
                {
                    continue;
                }
                if (dist[next_x][next_y] > dist[node.first][node.second] + 1)
                {
                    dist[next_x][next_y] = dist[node.first][node.second] + 1;
                    que.push({ next_x,next_y });
                    // ����0�����ǿ��Է��ʵ�
                    // ���ʹ��ˣ������������Է���
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
		// �������㵽�ﲻ��
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
            // ���¾���
			nums[nx][ny] = p.tot + 1;
            // �ܹ��ƶ����ýڵ㣬��ʾ�Ѿ��ҵ�������̾��룬ֱ�ӷ���
			if (nx == end_x && ny == end_y)
			{
				cout << nums[nx][ny];
				return 0;
			}
            // ���������ļ����Ž�������
			que.push({ nx,ny,p.tot + 1 });
		}
	}
	cout << -1;
	return 0;
}




