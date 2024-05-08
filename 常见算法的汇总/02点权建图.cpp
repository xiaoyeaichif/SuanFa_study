#include<iostream>
#include<vector>
using namespace std;


static const int N = 1E5 + 10;
static vector<int>g[N];  //领接表的vector写法 仅适用于点权建图
static int w[N];
//void dfs(int u, int fa) //如果是有向图 就不需要fa这个变量
//{
//    //do things
//    for (int& x : g[u]) //访问u的所有节点
//    {
//        if (x == fa)continue; //无向边才需要这一句 保证每个节点只会被访问一次(不理解的可以直接背过)
//        dfs(x, u);
//        // do things
//    }
//}

int main_graph04() {
    int n, m;  //n个点,m条边
    cin >> n >> m;
    //有向图
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);  //a->b建立一条边
    }
    //输出每个节点的与之相邻的点
    for (int i = 1; i <= n; i++)
    {
        cout << "Node" << i << " neighbors: ";
        for (auto& edge : g[i])
        {
            cout << "(" << edge << ") ";
        }
        cout << endl;
    }

    //给定顶点的权值
    for (int i = 1; i <= n; i++)cin >> w[i];
    return 0;
}