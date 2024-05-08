//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main05200() {
    unordered_map<int, vector<pair<int, int>>> path;

    // ��ӽڵ� 1 ���ڵ� 2 �ı�ȨΪ 3
    path[1].push_back({ 2, 3 });

    // �����ڵ� 1 ���������ڽڵ㼰��Ȩ
    int node = 1;

    // ���ڵ��Ƿ������ path ��
    if (path.count(node) > 0) {
        // �����ڵ�����ڽڵ�ͱ�Ȩ
        for (size_t i = 0; i < path[node].size(); i++) {
            int target = path[node][i].first;
            int weight = path[node][i].second;
            // ������ڽڵ�ͱ�Ȩ��Ϣ
            cout << "From node " << node << " to node " << target << " with weight " << weight << endl;
        }
    }
    else {
        cout << "Node " << node << " does not have any adjacent nodes." << endl;
    }

    return 0;
}
