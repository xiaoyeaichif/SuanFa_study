//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

static const int N = 100000 + 10;
static vector<int>nums(N, 0);

/*
    实现一个函数,输入数组和value，输出数组的和
*/

long long check(vector<int>& nums, int value)
{
    long long sum = 0;
    for (int num : nums)
    {
        sum += min(value, num);
    }
    return sum;
}

//主函数
int main_erfen03()
{
    int index = 0;
    int x;
    while (cin >> x)
    {
        nums[index] = x;
        cout << nums[index] << ' ';
        index++;
        
    }
    cout << "输出" << endl;
    //int cnt;
    //cin >> cnt;
    ////先检查所有的元素和是否小于cnt
    //long long  sum = 0;
    //for (int i = 0; i < index; i++)
    //{
    //    sum += nums[i];
    //}
    //if (sum <= cnt)
    //{
    //    cout << -1 << endl;
    //}
    //else {
    //    int l = 0;
    //    int r = 0;
    //    for (int i = 0; i < index; i++)
    //    {
    //        r = max(r, nums[i]);
    //    }
    //    int ans = 0;
    //    while (l <= r)
    //    {
    //        int mid = l + (r - l) / 2;
    //        if (check(nums, mid) <= cnt)
    //        {
    //            ans = mid;
    //            l = mid + 1;
    //        }
    //        else {
    //            r = mid - 1;
    //        }
    //    }
    //    cout << ans << endl;
    //}
    return 0;
}