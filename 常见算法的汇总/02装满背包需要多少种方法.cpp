#include<iostream>
#include<vector>


using namespace std;

const int mod = 1e9 + 7;

int main() {
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
    cout << dp[0][target] << endl;
    return 0;
}
