#include <iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int>nums(10, 0);
    for (int i = 0; i < n; i++)
    {
        // 投票的个数统计
        vector<int>p(10, 0);
        // 输入票数
        for (int j = 0; j < 10; j++)
        {
            cin >> p[i];
        }
        // 统计有效票数
        int count_1 = 0, count_2 = 0;
        for (int k = 0; k < 10; k++)
        {
            if (p[i] == 1)
            {
                count_1++;
            }
            else if (p[i] == 2)
            {
                count_2++;
            }
        }
        int count_all = count_1 + count_2;
        // 检查是否不合理
        if (count_all < 3 || count_2 > 5 || count_2 > count_all - 2)
        {
            continue;
        }
        // 统计合理的票数
        for (int x = 0; x < 10; x++)
        {
            if (p[x] == 2)
            {
                nums[x]++;
            }
        }
    }
    // 输出最大值
    int maxValue = *max_element(nums.begin(), nums.end());
    for (int y = 0; y < 10; y++)
    {
        if (nums[y] == maxValue)
        {
            cout << y + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")