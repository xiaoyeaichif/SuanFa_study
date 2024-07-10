#include<iostream>
#include<vector>
using namespace std;

/*
    * �������Ŀ�����жϣ���ͨ���У���ȫ��ͨ�����������ȫ��ͨ��ָ����
    * n�������n * ��n-1�� / 2���ߣ���������ͨ���Ϊ��ȫ��ͨ����
    2: �������һ���ص���Ǳߵ���������ôͳ�Ƶģ��Ƚ�����˼
*/


class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        Father.resize(n);
        Size.resize(n);
        Graph.resize(n);
        for (int i = 0; i < n; i++)
        {
            Father[i] = i;
            Size[i] = 1;
            Graph[i] = 0;
        }
        for (auto& edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            Unoin(x, y);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (Find(i) == i)
            {
                if (Size[i] <= 2)
                {
                    ans += 1;
                }
                //Graph[i]���ߵĸ���
                //Size[i]����ĸ���
                //Size[i] * (Size[i] - 1) / 2 �� ��ȫͼ�ߵĸ���
                else if (Graph[i] == Size[i] * (Size[i] - 1) / 2)
                {
                    ans += 1;
                }
            }
        }
        return ans;
    }
    //ʹ�ò��鼯,����Ҫͳ�Ʊߵĸ���
    vector<int>Father;
    vector<int>Size;
    vector<int>Graph;
    //Find������ʵ��
    int Find(int x)
    {
        if (x != Father[x])
        {
            Father[x] = Find(Father[x]);
        }
        return Father[x];
    }
    //Union������ʵ��
    void Unoin(int x, int y)
    {
        int root_x = Find(x);
        int root_y = Find(y);
        if (root_x != root_y)
        {
            //x����y��
            Father[root_x] = root_y;
            Size[root_y] += Size[root_x];
            Graph[root_y] += Graph[root_x] + 1;
        }
        else {
            //root_x == root_y
            Graph[root_y] += 1;
        }
    }
};

int main_bingchaji06()
{
    int n;
    cin >> n;
    vector<vector<int>>edges = { {0,1} ,{0,2},{1,2},{3,4} };
    Solution s1;
    cout << s1.countCompleteComponents(n, edges);
    return 0;
    
}