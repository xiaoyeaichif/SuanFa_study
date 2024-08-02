#include<iostream>
#include<vector>


using namespace std;

const int mod = 1e9 + 7;

// ����װ����Ҫ�����ַ�����״̬ѹ���汾
// ѹ��ʱ������Ҫ�Ӻ���ǰ������������ֱ�ӻ�ͼ��⣬�Ƚϼ��׶�
// ����ֱ��dp[i][j]֮��dp[i+1][j],dp[i+1][j - nums[i]]�йأ�Ҳ����˵j����Ԫ��
// ֻ����֮ǰ���ֵ�Ԫ���й�,�����ǰ�����죬ǰ���Ԫ���п��ܻᱻ���ǵ����Ӻ���ǰ�Ͳ��������ֹ���
vector<int> getCount(vector<int>& w, int bag)
{
    int n = w.size();
    vector<int>dp(bag + 1, 0); // ��õĸ�������
    dp[0] = 1; // ��ʾ����Խ�磬���Ǳ�������Ϊ0��Ҳ�����ҵ�һ�ַ���������װ��
    for (int i = 0; i < n; i++) // ��ʾ��Ҫ�����Ĵ���
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
// �������������һ��д��
// ǰi��Ԫ����ѡȡ���ɸ�Ԫ�أ�ʹ�ñ�������װ���ķ�����
vector<vector<int>>getCount1(vector<int>& nums, int bag)
{
    int n = nums.size();
    vector<vector<int>>dp(n + 1, vector<int>(bag + 1, 0));
    // ��ʼ����
    dp[0][0] = 1;  // ��ѡ���κ���Ʒʱ����������Ϊ0�ķ�������Ϊ1
    for (int i = 1; i <= n; i++) {
        for (int rest = 0; rest <= bag; rest++) {
            // ��ʾ��ǰʲô������,����ά��ԭ״
            int p1 = dp[i - 1][rest];
            // ��ʾ��ǰ�ı��������ܷ��µ�ǰ��Ԫ��
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
    cout << dp[0][target] << endl; // 
    // ���dp���������״̬
    cout <<"�±�����İ汾: " << endl;
    for (auto temp : dp)
    {
        for (auto a : temp)
        {
            cout << a << ' ';
        }
        cout << endl;
    }
    cout << "״̬ѹ���汾: " << endl;
    // ״̬ѹ���汾
    vector<int>ans = getCount(nums, target);
    for (int num : ans)
    {
        cout << num << ' ';
    }
    cout << endl;
    // 
    cout << "ǰ׺����汾: " << endl;
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
