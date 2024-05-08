//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main05200() {
    unordered_map<int, vector<pair<int, int>>> path;

    // 添加节点 1 到节点 2 的边权为 3
    path[1].push_back({ 2, 3 });

    // 遍历节点 1 的所有相邻节点及边权
    int node = 1;

    // 检查节点是否存在于 path 中
    if (path.count(node) > 0) {
        // 遍历节点的相邻节点和边权
        for (size_t i = 0; i < path[node].size(); i++) {
            int target = path[node][i].first;
            int weight = path[node][i].second;
            // 输出相邻节点和边权信息
            cout << "From node " << node << " to node " << target << " with weight " << weight << endl;
        }
    }
    else {
        cout << "Node " << node << " does not have any adjacent nodes." << endl;
    }

    return 0;
}
