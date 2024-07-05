



#include<iostream>
#include<vector>
using namespace std;
const int N = 110;

static vector<int>nums(N, 0);
static vector<int>preMax(N, 1); // 前缀最长的上升子序列
static vector<int>houMax(N, 1); // 后缀最长上升子序列



int main_xulie01()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    //前缀的最长上升子序列
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
    
    //输出检查
    for (int i = 1; i <= n; i++)
    {
        cout << preMax[i] << ' ';
    }
    cout << endl;


    //后缀的最大长度
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
    //统计当前的i左右两侧能获得的最大上升子序列
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