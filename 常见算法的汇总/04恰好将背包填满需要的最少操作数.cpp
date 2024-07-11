


// 输出能获取的最大值


#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e9;

static vector<int> get_yasuo(vector<int>& w, int target)
{
    int n = w.size();
    vector<int>ans(target + 1, INF);
    ans[0] = 0; // 初始化背包容量为0时的操作次数为0

    for (int i = 1; i <= n; i++) // 滚动数组的次数，对应原二维DP中的行
    {
        for (int rest = target; rest >= w[i - 1]; rest--) // 避免数组越界，从target向下递减
        {
            int p1 = ans[rest]; // 相当于原二维DP中的ans[i-1][rest]
            int p2 = ans[rest - w[i - 1]] + 1; // 相当于原二维DP中的ans[i-1][rest-w[i-1]]+1
            ans[rest] = min(p1, p2);
        }
    }
    return ans;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int>nums(n);
    // 背包的容量为 m 
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // 前i个元素中选取元素，恰好将容量为bag的背包填满，能获取的最小操作数
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, INF));
    /*
        初始化分为两个部分
        1：背包容量为0，所以将背包填满的最小操作数就是0
        2：i == 0，如果 背包容量也为0，一次都不用操作，如果不为 0，则操作次数为无穷大
            因为，i == 0 代表没有元素，不可能往背包里面填元素
    */
    //初始化部分,初始化第一列
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) // 循环中的都代表前i个，所以下标应该时i-1
        {
            // 当前i-1的下标没有选取,所以最小值为前面的最小值
            int p1 = dp[i - 1][j]; 
            int p2 = INT_MAX;
            // 选取当前的i-1元素,要先判断背包的容量够不够，操作次数+1
            if (j - nums[i - 1] >= 0)
            {
                p2 = dp[i - 1][j - nums[i - 1]] + 1;
            }
            dp[i][j] = min(p1, p2);
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
    cout << "**************压缩数组的部分：*********" << endl;
    vector<int>ans = get_yasuo(nums,m);
    for (int num : ans)
    {
        cout << num << ' ';
    }
    cout << endl;
    cout << "背包填满的最小操作次数为: " << dp[n][m] << endl;
    return 0;
}