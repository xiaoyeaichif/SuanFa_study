#include<iostream>
#include <vector>
#include <limits.h>


using namespace std;

int maximumEnergy(vector<int>& energy, int k) {
    int ans = INT_MIN;
    int N = energy.size();
    int l = 0, r = 0;
    for (; l < N; l++)
    {
        int sum = 0;
        r = l;
        while (r < N)
        {
            sum += energy[r];
            r += k;
        }
        ans = max(ans, sum);
    }
    return ans;
}

int main_week01()
{
    vector<int>nums = { 5,2,-10,-5,1 };
    int k = 3;
    int ans = maximumEnergy(nums, k);
    cout << ans <<endl;
    return 0;
}