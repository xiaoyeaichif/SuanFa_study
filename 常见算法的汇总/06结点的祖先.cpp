#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //�ڽӱ���ͼ�Ĺ�ϵ
        vector<vector<int>>g(n);
        ans = vector<vector<int>>(n);
        for (auto& edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            g[x].push_back(y);
        }
        //����һ��used����,��������Ѿ����ʹ���Ԫ��
        //��ʼ��Ϊ-1����û�з���
        vector<int>used(n, -1);
        for (int start = 0; start < n; start++)
        {
            dfs(g, used, start, start);
        }
        return ans;
    }
    //dfs������д��
    void dfs(vector<vector<int>>& g, vector<int>& used, int u, int start)
    {
        used[u] = start;
        for (auto& x : g[u])
        {
            if (used[x] != start)
            {
                ans[x].push_back(start);
                dfs(g, used, x, start);
            }
        }
    }
};

int main_tree06()
{
    vector<vector<int>>edges = { {0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6} };
    int n = edges.size();
    Solution s1;
    auto ans = s1.getAncestors(n,edges);
    for (auto num : ans)
    {
        for (int a : num)
        {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}