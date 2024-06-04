#include<iostream>
#include<vector>
using namespace std;
//邻接表建图
static const int N = 100010;

static vector<int>g[N];//本质上是一个二维矩阵
static int n;
static int w[N];//记录个数





//第二种dfs方案，建立有向图
int dfs(int u)
{
    // 初始化当前节点的子树节点数目
    w[u] = 1;
    // 遍历所有子节点
    for (int v : g[u]) {
        w[u] += dfs(v);
    }
    // 包括当前节点本身
    return w[u];
}

//主函数的实现
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    //递归遍历
    //根节点为1,
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << w[i] << ' ';
    }
    return 0;
}