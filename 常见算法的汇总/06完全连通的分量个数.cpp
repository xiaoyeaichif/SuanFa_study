#include<iostream>
#include<vector>
using namespace std;

/*
    * 本代码的目的是判断，连通块中，完全连通块的数量，完全连通块指的是
    * n个点就有n * （n-1） / 2条边，这样的连通块称为完全联通分量
    2: 本题的另一个重点就是边的数量是怎么统计的，比较有意思
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
                //Graph[i]：边的个数
                //Size[i]：点的个数
                //Size[i] * (Size[i] - 1) / 2 ： 完全图边的个数
                else if (Graph[i] == Size[i] * (Size[i] - 1) / 2)
                {
                    ans += 1;
                }
            }
        }
        return ans;
    }
    //使用并查集,但是要统计边的个数
    vector<int>Father;
    vector<int>Size;
    vector<int>Graph;
    //Find函数的实现
    int Find(int x)
    {
        if (x != Father[x])
        {
            Father[x] = Find(Father[x]);
        }
        return Father[x];
    }
    //Union函数的实现
    void Unoin(int x, int y)
    {
        int root_x = Find(x);
        int root_y = Find(y);
        if (root_x != root_y)
        {
            //x挂在y上
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