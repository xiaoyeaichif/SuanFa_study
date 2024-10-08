

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;

static const int N = 1E5 + 10;

static vector<int>Input(N, 0);
vector<int>nums[N]; // 邻接表

static void tpsort()
{
    queue<int>que;
    // 检查是否有环的序列，也就是能不能输出大小为n
    vector<int>ans;
    for (int i = 1; i <= n; i++)
    {
        if (Input[i] == 0)
        {
            que.push(i);
        }
    }
    // 检查队列是否为空即可
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            int node = que.front();
            que.pop();
            ans.push_back(node);
            for (int num : nums[node])
            {
                // 入度减1
                Input[num]--;
                // 将入度为0的点加入队列中
                if (Input[num] == 0)
                {
                    que.push(num);
                }
            }
        }
    }
    if (ans.size() == n)
    {
        cout << "YES" << endl;
    }
    else {
        cout << ans.size() << endl;
    }
}


int main_tpsort03()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        nums[a].push_back(b);
        // 更新入度的大小
        Input[b]++;
    }
    // 拓扑排序的内容
    tpsort();
    //
    return 0;
}



