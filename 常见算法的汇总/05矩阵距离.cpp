

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1010;
static vector<vector<int>>dist(N, vector<int>(N, INT_MAX)); //��ʼ������Ϊ���ֵ
static vector<vector<int>>nums(N, vector<int>(N, 0));
static int n, m;
static int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int main_bfs05()
{
    cin >> n >> m;
    queue<pair<int, int>>que;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> nums[i][j];
            if (nums[i][j] == 1)
            {
                if (j == 1)
                {
                    dist[i][j] = 0;
                    que.push({ i,j });
                }
            }
        }
    }

    //��������bfs�Ĺ���
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            auto node = que.front();
            int node_x = node.first;
            int node_y = node.second;
            que.pop();
            //�����ĸ�����
            for (int i = 0; i < 4; i++)
            {
                int x = dx[i] + node_x;
                int y = dy[i] + node_y;
                if (x < 1 || x > n || y < 1 || y > m) continue;
                if (nums[x][y] == 0) continue;
                //���µ�ǰ�ĵ��֮ǰ��ľ���
                if (dist[x][y] > dist[node_x][node_y] + 1)
                {
                    dist[x][y] = dist[node_x][node_y] + 1;
                    que.push({ x,y });
                }
                
            }
        }
    }
    //������߼�
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
