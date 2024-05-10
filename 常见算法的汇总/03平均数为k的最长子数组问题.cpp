

/*
    将题目转化一下,要想获取平均数等于k的最长连续子数组
    比如:
        1 3 2 4 1
    要求平均数为2的最长子数组为1 3 2这部分
    1 + 3 +2 / 3 == 2
    两边同时减去2
    1 + 3+ 2/ 3 - 2 = 2 - 2
    左边 = ( (1-2) + (3 -2) + (2-2) ) / 3
    所以将整个数组都减去平均数k, 就转化为求和为0的最长子数组问题

*/

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//static const int N = 100000+10;

//返回最大长度
//和为0的最长子数组
int get_max_length(vector<int>& nums, int k)
{
    int N = nums.size();
    long long Presum = 0;
    unordered_map<long long, int>u_map;
    u_map[0] = -1;
    //记录最大长度
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        Presum += nums[i];
        if (u_map.find(Presum - 0) != u_map.end())
        {
            ans = max(ans, i - u_map[Presum]);
        }
        else {
            u_map[Presum] = i;
        }
    }
    return ans;
}

int main_qz003()
{
    int n, m;
    cin >> n >> m;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        nums[i] = nums[i] - m;
    }
    int ans = get_max_length(nums, m);
    cout << ans << endl;
    return 0;
}