//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

const int N = 53;

int main0417()
{
    int n;
    cin >> n;
    vector<string>nums(N);
    vector<string>ans(N);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    //Ïû³ý¹ý³Ì
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        ans[r++] = nums[i];
        while (r >= 3 && ans[r-1] == ans[r - 2] && ans[r-3] == ans[r - 2])
        {
            r -= 3;
        }
    }
    if (r == 0) cout << 0 << endl;
    for (int i = 0; i < r; i++)
    {
        if (i == r - 1)
        {
            cout << ans[i];
        }
        else {
            cout << ans[i] << ' ';
        }
    }
    return 0;
}