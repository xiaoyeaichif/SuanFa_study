//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
static const int N = 1E5 + 10;
static vector<int>g[N];  //领接表的vector写法 仅适用于点权建图
static int w[N];    //w[i]记录以i为根节点的子树中的节点数量
static int dfs(int u, int fa) //如果是有向图 就不需要fa这个变量
{
    w[u] = 1;  //自身算作一个节点
    for (int& x : g[u]) //访问u的所有节点
    {
        if (x == fa)continue; //无向边才需要这一句 保证每个节点只会被访问一次(不理解的可以直接背过)
        w[u] += dfs(x, u);
    }
    return w[u];
}

int main_tree01() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);  //a->b建立一条边
        g[b].push_back(a);   //b->a建立一条边
    }
    dfs(1, 0);  //从根节点开始，自顶向下搜索,以1为根节点
    for (int i = 1; i <= n; i++) {
        cout << w[i] << " ";
    }
    return 0;
}