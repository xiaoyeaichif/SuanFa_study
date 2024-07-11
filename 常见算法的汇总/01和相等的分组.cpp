
#include<iostream>
#include<vector>
#include<sstream>


// 分析，两组之和战力相同，也就是说不能出现奇数
// 出现奇数就会导致不能整除
using namespace std;

// 压缩数组的方式
vector<int> yasuo(vector<int>& w, vector<int>& value,int target)
{
    int n = w.size();
    vector<int>ans(target + 1, 0);
    int index = w.size();
    for (int i = index - 1; i >= 0; i--)
    {
        for (int rest = target; rest - w[i] >= 0; rest--)
        {
            int p1 = ans[rest]; // 相当于ans[i][rest]
            int p2 = ans[rest - w[i]] + value[i]; // 相当于 ans[i][rest - w[i]] + value[i]
            ans[rest] = max(p1, p2);
        }
    }
    return ans;
}

// 背包的问题的模板  
// 返回获取使背包装下的价值最大
int beibao(vector<int>& w, vector<int>& value, int bag)
{
    // 获取背包的能装下的最大值
    int n = w.size();
    /*
        选择下标i的元素装进背包能获得的最大值
    */
    vector<vector<int>>dp(n + 1, vector<int>(bag + 1, 0));
    // 初始化,i == n时，下标已经越界，所以价值为0
    for (int j = 0; j < bag + 1; j++)
    {
        dp[n][j] = 0; // 其实在数组初始化的时候就已经初始化过了
    }
    // 填写整个表格
    for (int i = n - 1; i >= 0; i--)
    {
        for (int rest = 0; rest < bag + 1; rest++)
        {
            int p1 = dp[i+1][rest]; // 不选择当前元素，去下一个元素选择
            int p2 = 0;
            if (rest - w[i] >= 0)
            {
                p2 = dp[i+1][rest - w[i]] + value[i]; //选择当前元素，获取当前的价值，并去下一个元素
            }
            dp[i][rest] = max(p1, p2);
        }
    }
    return dp[0][bag];
}

int main_bag01()
{
    string str;
    getline(cin, str);
    istringstream iss(str);
    vector<int>nums;
    vector<int>res;
    int number;
    while (iss >> number)
    {
        nums.push_back(number);
    }
    int targetSum = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        targetSum += nums[i];
        res.push_back(nums[i]);
    }
    if (targetSum % 2 == 1)
    {
        cout << 0 << endl; return 0;
    }
    int target = targetSum / 2;

    // 创建dp数组
    int index = res.size();
    vector<vector<int>>dp(index + 1, vector<int>(target + 1, 0));
    // 初始化一部分
    for (int j = 0; j < target + 1; j++)
    {
        dp[index][j] = 0;
    }
    for (int i = index - 1; i >= 0; i--)
    {
        for (int rest = 0; rest <= target; rest++)
        {
            int p1 = dp[i + 1][rest];
            int p2 = 0;
            if (rest - res[i] >= 0)
            {
                p2 = dp[i + 1][rest - res[i]] + res[i];
            }
            dp[i][rest] = max(p1, p2);
        }
    }
    for (int i = 0; i < index + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    // 优化的部分
    cout << "****************************** " << endl;
    auto ans = yasuo(res, res, target);
    for (int num : ans)
    {
        cout << num << ' '; 
    }
    cout << endl;
    cout << "**********************************" << endl;
    cout << "模板: " << beibao(res, res, target);
    return 0;

}