
#include<iostream>
#include<vector>
#include<sstream>


// ����������֮��ս����ͬ��Ҳ����˵���ܳ�������
// ���������ͻᵼ�²�������
using namespace std;

// ѹ������ķ�ʽ
vector<int> yasuo(vector<int>& w, vector<int>& value,int target)
{
    int n = w.size();
    vector<int>ans(target + 1, 0);
    int index = w.size();
    for (int i = index - 1; i >= 0; i--)
    {
        for (int rest = target; rest - w[i] >= 0; rest--)
        {
            int p1 = ans[rest]; // �൱��ans[i][rest]
            int p2 = ans[rest - w[i]] + value[i]; // �൱�� ans[i][rest - w[i]] + value[i]
            ans[rest] = max(p1, p2);
        }
    }
    return ans;
}

// �����������ģ��  
// ���ػ�ȡʹ����װ�µļ�ֵ���
int beibao(vector<int>& w, vector<int>& value, int bag)
{
    // ��ȡ��������װ�µ����ֵ
    int n = w.size();
    /*
        ѡ���±�i��Ԫ��װ�������ܻ�õ����ֵ
    */
    vector<vector<int>>dp(n + 1, vector<int>(bag + 1, 0));
    // ��ʼ��,i == nʱ���±��Ѿ�Խ�磬���Լ�ֵΪ0
    for (int j = 0; j < bag + 1; j++)
    {
        dp[n][j] = 0; // ��ʵ�������ʼ����ʱ����Ѿ���ʼ������
    }
    // ��д�������
    for (int i = n - 1; i >= 0; i--)
    {
        for (int rest = 0; rest < bag + 1; rest++)
        {
            int p1 = dp[i+1][rest]; // ��ѡ��ǰԪ�أ�ȥ��һ��Ԫ��ѡ��
            int p2 = 0;
            if (rest - w[i] >= 0)
            {
                p2 = dp[i+1][rest - w[i]] + value[i]; //ѡ��ǰԪ�أ���ȡ��ǰ�ļ�ֵ����ȥ��һ��Ԫ��
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

    // ����dp����
    int index = res.size();
    vector<vector<int>>dp(index + 1, vector<int>(target + 1, 0));
    // ��ʼ��һ����
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
    // �Ż��Ĳ���
    cout << "****************************** " << endl;
    auto ans = yasuo(res, res, target);
    for (int num : ans)
    {
        cout << num << ' '; 
    }
    cout << endl;
    cout << "**********************************" << endl;
    cout << "ģ��: " << beibao(res, res, target);
    return 0;

}