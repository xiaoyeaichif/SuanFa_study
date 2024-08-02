

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int N = 30;
static vector<int>Input_(N, 0); // 表示入度
static vector<int>g[N];
static int nums[N][N];
static vector<int>value(N, 0);

static int n;

// 层序遍历的应用
static void tpsort()
{
    queue<int>que;
    for (int i = 1; i <= n; i++)
    {
        if (Input_[i] == 0)
        {
            que.push(i);
        }
    }
    vector<int>ans; // 记录所有的元素
    int cnt = 0; // 记录最终需要的最小内存
    while (!que.empty())
    {
        int size = que.size();
        int res = 0;
        while (size--)
        {
            int node = que.front();
            que.pop();
            ans.push_back(node);
            res += value[node]; // 更新每一层对应的值
            for (int& num : g[node])
            {
                Input_[num]--;
                if (Input_[num] == 0)
                {
                    que.push(num);
                }
            }
        }
        cnt = max(cnt, res);
    }
    int size_ = ans.size();
    if (size_ == n)
    {
        cout << cnt << endl;
    }
    else {
        cout << -1 << endl;
    }
}


// 主函数逻辑
int main_tpsort02()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }
    // 建立邻接矩阵
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) // 循环输入
        {
            cin >> nums[i][j];
            if (nums[i][j] != 0)
            {
                g[j].push_back(i);
                Input_[i]++; // 入度的书写
            }
        }
    }
    tpsort();
    return 0;
}

