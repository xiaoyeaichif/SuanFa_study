#include<iostream>
#include<vector>


using namespace std;

const int mod = 1e9 + 7;

// 背包装满需要多少种方法的状态压缩版本
// 压缩时遍历需要从后往前填，具体分析可以直接画图理解，比较简单易懂
// 我们直到dp[i][j]之和dp[i+1][j],dp[i+1][j - nums[i]]有关，也就是说j处的元素
// 只与他之前出现的元素有关,如果从前往后天，前面的元素有可能会被覆盖掉，从后往前就不会有这种顾虑
vector<int> getCount(vector<int>& w, int bag)
{
    int n = w.size();
    vector<int>dp(bag + 1, 0); // 获得的个数数组
    dp[0] = 1; // 表示数组越界，但是背包容量为0，也就是找到一种方法将背包装满
    for (int i = 0; i < n; i++) // 表示需要滚动的次数
    {
        for (int rest = bag; rest - w[i] >= 0; rest--)
        {
            int p1 = dp[rest];
            int p2 = dp[rest - w[i]];
            dp[rest] = p1 + p2;
        }
    }
    return dp;
}
// 背包问题的另外一种写法
// 前i个元素中选取若干个元素，使得背包容量装满的方案数
vector<vector<int>>getCount1(vector<int>& nums, int bag)
{
    int n = nums.size();
    vector<vector<int>>dp(n + 1, vector<int>(bag + 1, 0));
    // 初始化表
    dp[0][0] = 1;  // 不选择任何物品时，背包重量为0的方案数量为1
    for (int i = 1; i <= n; i++) {
        for (int rest = 0; rest <= bag; rest++) {
            // 表示当前什么都不做,所以维持原状
            int p1 = dp[i - 1][rest];
            // 表示当前的背包容量能放下当前的元素
            int p2 = 0;
            if (rest >= nums[i - 1]) {
                p2 = dp[i - 1][rest - nums[i - 1]];
            }
            dp[i][rest] = (p1 + p2) % mod;
        }
    }
    return dp;
}

int main_bag02() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    int targetSum = 0;

    // 读取输入的数字并计算总和
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        targetSum += nums[i];
    }

    // 如果总和为奇数，无法分成两组相等的和
    if (targetSum % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    int target = targetSum / 2;
    // 要统计的是装满背包有多少种方法
    vector<vector<int>>dp(n + 1, vector<int>(target + 1, 0));
    // 初始化表
    dp[n][0] = 1; // 数组下标越界，此时背包容量正好为0，代表一种合理的方法
    for (int i = n - 1; i >= 0; i--)
    {
        for (int rest = 0; rest <= target; rest++)
        {
            int p1 = dp[i + 1][rest];
            int p2 = 0;
            if (rest - nums[i] >= 0)
            {
                p2 = dp[i + 1][rest - nums[i]];
            }
            dp[i][rest] = (p1 + p2) % mod;  // 代表有多少种方法
        }
    }
    cout << dp[0][target] << endl; // 
    // 输出dp数组的所有状态
    cout <<"下标衡量的版本: " << endl;
    for (auto temp : dp)
    {
        for (auto a : temp)
        {
            cout << a << ' ';
        }
        cout << endl;
    }
    cout << "状态压缩版本: " << endl;
    // 状态压缩版本
    vector<int>ans = getCount(nums, target);
    for (int num : ans)
    {
        cout << num << ' ';
    }
    cout << endl;
    // 
    cout << "前缀数组版本: " << endl;
    vector<vector<int>>res = getCount1(nums, target);
    for (auto temp : res)
    {
        for (auto a : temp)
        {
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}
