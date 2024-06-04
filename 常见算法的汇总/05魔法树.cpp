#include<iostream>
#include<vector>
#include<string>
using namespace std;
static const int N = 1010;
static long long n, r, l;
static string s;
static vector<int>g[N];
static long long res;
static void dfs(int u, int fa, long long total)   //枚举以u为终点的路径
{
    total = total * 2 + (s[u] - '0');
    if (total > 1e18)return; //防止爆long long
    if (fa != -1)   //说明路径长度至少为1
    {
        if (total >= l && total <= r)res++;
    }
    for (int& x : g[u])
    {
        if (x == fa)continue;  //无向边
        dfs(x, u, total);   //继续搜索其他路径
    }
}

int main()
{
    cin >> n >> l >> r;
    cin >> s;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //轮流遍历子节点
    //使得结点的值可以往后移动一个单位,可以和结点的下标正好对应上
    s = ' ' + s;
    for (int i = 1; i <= n; i++)  //对每一个点跑一遍DFS，枚举以i为起点的路径
    {
        dfs(i, -1, 0);
    }
    cout << res << endl;
    return 0;
}
