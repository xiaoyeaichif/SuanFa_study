



#include<iostream>
#include<vector>
using namespace std;
const int N = 110;

static vector<int>nums(N, 0);
static vector<int>preMax(N, 1); // ǰ׺�������������
static vector<int>houMax(N, 1); // ��׺�����������



int main_xulie01()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    //ǰ׺�������������
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                preMax[i] = max(preMax[i], preMax[j] + 1);
            }
        }
    }
    
    //������
    for (int i = 1; i <= n; i++)
    {
        cout << preMax[i] << ' ';
    }
    cout << endl;


    //��׺����󳤶�
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = n; j > i; j--)
        {
            if (nums[i] > nums[j])
            {
                houMax[i] = max(houMax[i], houMax[j] + 1);
            }
        }
    }
    //ͳ�Ƶ�ǰ��i���������ܻ�õ��������������
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, n - (preMax[i] + houMax[i] - 1));
    }
    for (int i = 1; i <= n; i++)
    {
        cout << houMax[i] << ' ';
    }
    //cout << ans << endl;
    return 0;
}