#include<iostream>
#include<vector>
using namespace std;
//�ڽӱ�ͼ
static const int N = 100010;

static vector<int>g[N];//��������һ����ά����
static int n;
static int w[N];//��¼����





//�ڶ���dfs��������������ͼ
int dfs(int u)
{
    // ��ʼ����ǰ�ڵ�������ڵ���Ŀ
    w[u] = 1;
    // ���������ӽڵ�
    for (int v : g[u]) {
        w[u] += dfs(v);
    }
    // ������ǰ�ڵ㱾��
    return w[u];
}

//��������ʵ��
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    //�ݹ����
    //���ڵ�Ϊ1,
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << w[i] << ' ';
    }
    return 0;
}