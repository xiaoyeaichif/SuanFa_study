


// ����ܻ�ȡ�����ֵ


#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e9;

static vector<int> get_yasuo(vector<int>& w, int target)
{
    int n = w.size();
    vector<int>ans(target + 1, INF);
    ans[0] = 0; // ��ʼ����������Ϊ0ʱ�Ĳ�������Ϊ0

    for (int i = 1; i <= n; i++) // ��������Ĵ�������Ӧԭ��άDP�е���
    {
        for (int rest = target; rest >= w[i - 1]; rest--) // ��������Խ�磬��target���µݼ�
        {
            int p1 = ans[rest]; // �൱��ԭ��άDP�е�ans[i-1][rest]
            int p2 = ans[rest - w[i - 1]] + 1; // �൱��ԭ��άDP�е�ans[i-1][rest-w[i-1]]+1
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
    // ����������Ϊ m 
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // ǰi��Ԫ����ѡȡԪ�أ�ǡ�ý�����Ϊbag�ı����������ܻ�ȡ����С������
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, INF));
    /*
        ��ʼ����Ϊ��������
        1����������Ϊ0�����Խ�������������С����������0
        2��i == 0����� ��������ҲΪ0��һ�ζ����ò����������Ϊ 0�����������Ϊ�����
            ��Ϊ��i == 0 ����û��Ԫ�أ�������������������Ԫ��
    */
    //��ʼ������,��ʼ����һ��
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) // ѭ���еĶ�����ǰi���������±�Ӧ��ʱi-1
        {
            // ��ǰi-1���±�û��ѡȡ,������СֵΪǰ�����Сֵ
            int p1 = dp[i - 1][j]; 
            int p2 = INT_MAX;
            // ѡȡ��ǰ��i-1Ԫ��,Ҫ���жϱ�������������������������+1
            if (j - nums[i - 1] >= 0)
            {
                p2 = dp[i - 1][j - nums[i - 1]] + 1;
            }
            dp[i][j] = min(p1, p2);
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
    cout << "**************ѹ������Ĳ��֣�*********" << endl;
    vector<int>ans = get_yasuo(nums,m);
    for (int num : ans)
    {
        cout << num << ' ';
    }
    cout << endl;
    cout << "������������С��������Ϊ: " << dp[n][m] << endl;
    return 0;
}