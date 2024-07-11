


// ����ܻ�ȡ�����ֵ


#include<iostream>
#include<vector>
using namespace std;

vector<int> get_yasuo(vector<int>& w, vector<int>& value, int target)
{
    int n = w.size();
    vector<int>ans(target + 1, 0);
    int index = w.size();
    for (int i = 1;i < index+1;i++) // ������ǹ�������Ĵ���
    {
        for (int rest = target;rest - w[i-1] >= 0;rest--)
        {
            int p1 = ans[rest]; // �൱��ans[i-1][rest]
            int p2 = ans[rest - w[i-1]] + value[i-1]; // �൱�� ans[i-1][rest - w[i-1]] + value[i-1]
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
    // ����������Ϊ m
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b; // ��ʼ����ֵ��������������
        nums[i] = a;
        values[i] = b;
    }
    // ǰi��Ԫ����ѡȡ�ܻ�ȡ�ĵ����ֵ�Ƕ���
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
    // ��ʼ������ʡ��
    // ����˵ ǰ 0 ��Ԫ���ܻ�õ�����ֵ�϶���0
    // ����Ϊ0ʱ�ܻ�õ�����ֵҲ��0
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) // ѭ���еĶ�����ǰi���������±�Ӧ��ʱi-1
        {
            // ��ǰi-1���±�û��ѡȡ
            int p1 = dp[i - 1][j]; // �������ֵ��Ϊǰ��һ�ε����ֵ
            int p2 = 0;
            // ѡȡ��ǰ��i-1Ԫ��,Ҫ���жϱ���������������
            if (j - nums[i - 1] >= 0)
            {
                p2 = dp[i - 1][j - nums[i - 1]] + values[i - 1];
            }
            dp[i][j] = max(p1, p2);
        }
    }
    cout << "**************û��ѹ������Ĳ��֣�*********" << endl;
    for (auto temp : dp)
    {
        for (auto a : temp)
        {
            cout << a << ' ';
        }
        cout << endl;
    }
    // 
    cout << "**************ѹ������Ĳ��֣�*********"<<endl;
    vector<int>ans = get_yasuo(nums, values, m);
    for (int num : ans)
    {
        cout << num << ' ';
    }
    cout << endl;
    cout << "�������ܻ�ȡ������ֵ��: " << dp[n][m] << endl;
    return 0;
}