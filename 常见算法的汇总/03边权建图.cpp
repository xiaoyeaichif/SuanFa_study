// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


typedef pair<int, int>PII;
#define x first
#define y second
typedef long long ll;
static const int N = 1E5 + 10;
static vector<PII>g[N];
static int n, f[N];


//void dfs(int u, int fa) {
//    for (auto& [x, w] : g[u]) {
//        if (x == fa)continue;
//        dfs(x, u);
//        //代码逻辑
//    }
//}
int main_graph03() {
    cin >> n;
    //构建边权图
    //n个点,n-1条边
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({ b,c });
        g[b].push_back({ a,c });
    }

    //n个点,n条边
    /*for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({ b,c });
        g[b].push_back({ a,c });
    }*/

    //遍历每个顶点能到达的相邻顶点以及边的权值
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " neighbors: ";
        //遍历每条边,输出每条边的关系图
        //edge为一个pair变量
        for (auto& edge : g[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
    return 0;
}