


// 输出能获取的最大值


#include<iostream>
#include<vector>
using namespace std;

vector<int> get_yasuo(vector<int>& w, vector<int>& value, int target)
{
    int n = w.size();
    vector<int>ans(target + 1, 0);
    int index = w.size();
    for (int i = 1;i < index+1;i++) // 代表的是滚动数组的次数
    {
        for (int rest = target;rest - w[i-1] >= 0;rest--)
        {
            int p1 = ans[rest]; // 相当于ans[i-1][rest]
            int p2 = ans[rest - w[i-1]] + value[i-1]; // 相当于 ans[i-1][rest - w[i-1]] + value[i-1]
            ans[rest] = max(p1, p2);
        }
    }
    return ans;
}



int main_bag03()
{
    int n, m;
    cin >> n >> m;
    vector<int>nums(n);
    vector<int>values(n);
    // 背包的容量为 m
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b; // 初始化价值数组与重量数组
        nums[i] = a;
        values[i] = b;
    }
    // 前i个元素中选取能获取的的最大值是多少
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
    // 初始化部分省略
    // 比如说 前 0 个元素能获得的最大价值肯定是0
    // 背包为0时能获得的最大价值也是0
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) // 循环中的都代表前i个，所以下标应该时i-1
        {
            // 当前i-1的下标没有选取
            int p1 = dp[i - 1][j]; // 所以最大值就为前面一次的最大值
            int p2 = 0;
            // 选取当前的i-1元素,要先判断背包的容量够不够
            if (j - nums[i - 1] >= 0)
            {
                p2 = dp[i - 1][j - nums[i - 1]] + values[i - 1];
            }
            dp[i][j] = max(p1, p2);
        }
    }
    cout << "**************没有压缩数组的部分：*********" << endl;
    for (auto temp : dp)
    {
        for (auto a : temp)
        {
            cout << a << ' ';
        }
        cout << endl;
    }
    // 
    cout << "**************压缩数组的部分：*********"<<endl;
    vector<int>ans = get_yasuo(nums, values, m);
    for (int num : ans)
    {
        cout << num << ' ';
    }
    cout << endl;
    cout << "背包的能获取的最大价值是: " << dp[n][m] << endl;
    return 0;
}