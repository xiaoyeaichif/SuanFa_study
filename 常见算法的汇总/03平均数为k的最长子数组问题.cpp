

/*
    ����Ŀת��һ��,Ҫ���ȡƽ��������k�������������
    ����:
        1 3 2 4 1
    Ҫ��ƽ����Ϊ2���������Ϊ1 3 2�ⲿ��
    1 + 3 +2 / 3 == 2
    ����ͬʱ��ȥ2
    1 + 3+ 2/ 3 - 2 = 2 - 2
    ��� = ( (1-2) + (3 -2) + (2-2) ) / 3
    ���Խ��������鶼��ȥƽ����k, ��ת��Ϊ���Ϊ0�������������

*/

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//static const int N = 100000+10;

//������󳤶�
//��Ϊ0���������
int get_max_length(vector<int>& nums, int k)
{
    int N = nums.size();
    long long Presum = 0;
    unordered_map<long long, int>u_map;
    u_map[0] = -1;
    //��¼��󳤶�
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