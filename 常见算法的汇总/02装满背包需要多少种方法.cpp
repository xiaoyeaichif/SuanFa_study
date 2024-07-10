#include<iostream>
#include<vector>


using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    int targetSum = 0;

    // ��ȡ��������ֲ������ܺ�
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        targetSum += nums[i];
    }

    // ����ܺ�Ϊ�������޷��ֳ�������ȵĺ�
    if (targetSum % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    int target = targetSum / 2;
    // Ҫͳ�Ƶ���װ�������ж����ַ���
    vector<vector<int>>dp(n + 1, vector<int>(target + 1, 0));
    // ��ʼ����
    dp[n][0] = 1; // �����±�Խ�磬��ʱ������������Ϊ0������һ�ֺ���ķ���
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
            dp[i][rest] = (p1 + p2) % mod;  // �����ж����ַ���
        }
    }
    cout << dp[0][target] << endl;
    return 0;
}
