#include<iostream>
#include<vector>
using namespace std;

//闭区间形式
int lower_bound1(vector<int>& nums, int target)
{
	int N = nums.size();
	int left = 0;
	int right = N - 1;
	while (left <= right) //最终left = right + 1
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else {
			right= mid - 1;
		}
	}
	return left;
}

//左闭右开区间形式
int lower_bound2(vector<int>& nums, int target)
{
	int N = nums.size();
	int left = 0;
	int right = N ;
	while (left < right) //最终left == right 退出
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else {
			right = mid ;
		}
	}
	return left;
}


int main_erfen01()
{
	vector<int>nums = { 1,2,5,6,7,8,9,10 };
	int target = 6;
	cout << "闭区间形式: " << lower_bound1(nums, target) << endl;
	cout << "左闭右开区间形式: " << lower_bound2(nums, target) << endl;
	return 0;
}