//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

static const int N = 100000 + 10;
static vector<int>nums(N, 0);

/*
    ʵ��һ������,���������value���������ĺ�
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

//������
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
    cout << "���" << endl;
    //int cnt;
    //cin >> cnt;
    ////�ȼ�����е�Ԫ�غ��Ƿ�С��cnt
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