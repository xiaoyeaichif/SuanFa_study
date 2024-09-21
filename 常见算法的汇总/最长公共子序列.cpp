#include <iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

int main_0921() {
    string str1;
    string str2;
    int num;
    vector<int> nums1, nums2;
    getline(cin,str1);
    getline(cin,str2);
    stringstream iss(str1);
    stringstream ess(str2);
    while (iss >> num)
    {
        nums1.push_back(num);
    }
    for (int& a : nums1)
    {
        cout << a << ' ';
    }
    cout << endl;

    //
    while (ess >> num)
    {
        nums2.push_back(num);
    }
    for (int& a : nums2)
    {
        cout << a << ' ';
    }
    cout << endl;


    // while((pos = str1.find(' ') != string::npos))
    // {
    //     num = stoi(str1.substr(0,pos));
    //     nums1.push_back(num);
    //     str1.erase(0,pos+1);
    // }
    // nums1.push_back(stoi(str1));
    // // 处理str2
    // while((pos = str2.find(' ') != string::npos))
    // {
    //     num = stoi(str2.substr(0,pos));
    //     nums2.push_back(num);
    //     str2.erase(0,pos+1);
    // }
    // nums2.push_back(stoi(str2));


    //// dp数组
    int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1, 0));
    // 初始化
    // 开始填表
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n1][n2] << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")

// 本题就是最长公共子序列问题