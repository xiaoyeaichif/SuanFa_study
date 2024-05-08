#include<iostream>
#include<vector>
using namespace std;


static const int N = 1E5 + 10;
static vector<int>g[N];  //��ӱ��vectorд�� �������ڵ�Ȩ��ͼ
static int w[N];
//void dfs(int u, int fa) //���������ͼ �Ͳ���Ҫfa�������
//{
//    //do things
//    for (int& x : g[u]) //����u�����нڵ�
//    {
//        if (x == fa)continue; //����߲���Ҫ��һ�� ��֤ÿ���ڵ�ֻ�ᱻ����һ��(�����Ŀ���ֱ�ӱ���)
//        dfs(x, u);
//        // do things
//    }
//}

int main_graph04() {
    int n, m;  //n����,m����
    cin >> n >> m;
    //����ͼ
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);  //a->b����һ����
    }
    //���ÿ���ڵ����֮���ڵĵ�
    for (int i = 1; i <= n; i++)
    {
        cout << "Node" << i << " neighbors: ";
        for (auto& edge : g[i])
        {
            cout << "(" << edge << ") ";
        }
        cout << endl;
    }

    //���������Ȩֵ
    for (int i = 1; i <= n; i++)cin >> w[i];
    return 0;
}