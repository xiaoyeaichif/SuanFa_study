//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<sstream>
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

//��������һ��д��
int main_erfen03_01()
{
    int n,cnt;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> cnt;
    //�ȼ�����е�Ԫ�غ��Ƿ�С��cnt
    long long  sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    if (sum <= cnt)
    {
        cout << -1 << endl;
    }
    else {
        int l = 0;
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            r = max(r, nums[i]);
        }
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(nums, mid) <= cnt)
            {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

//�ڶ���д��,��ʽ����
int main_erfen03_02()
{
    string line;
    getline(cin, line);

    //תΪ��ʽ����
    istringstream ss(line);
    vector<int>arr;
    int num;
    while (ss >> num)
    {
        arr.push_back(num);
    }
    int cnt;
    cin >> cnt;
    
    ////�ȼ�����е�Ԫ�غ��Ƿ�С��cnt
    long long  sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    if (sum <= cnt)
    {
        cout << -1 << endl;
    }
    else {
        int l = 0;
        int r = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            r = max(r, arr[i]);
        }
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(arr, mid) <= cnt)
            {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}