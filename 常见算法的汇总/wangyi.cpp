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
        // ͶƱ�ĸ���ͳ��
        vector<int>p(10, 0);
        // ����Ʊ��
        for (int j = 0; j < 10; j++)
        {
            cin >> p[i];
        }
        // ͳ����ЧƱ��
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
        // ����Ƿ񲻺���
        if (count_all < 3 || count_2 > 5 || count_2 > count_all - 2)
        {
            continue;
        }
        // ͳ�ƺ����Ʊ��
        for (int x = 0; x < 10; x++)
        {
            if (p[x] == 2)
            {
                nums[x]++;
            }
        }
    }
    // ������ֵ
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
// 64 λ������� printf("%lld")