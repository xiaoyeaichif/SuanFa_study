

#include<iostream>
#include<vector>
using namespace std;

static int lower_bound(vector<int>& res, int target)
{
	int left = 0;
	int right = res.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (res[mid] < target)
		{
			left = mid + 1;
		}
		else {
			right = mid - 1; // 往左侧靠，找到最左侧的满足的元素下标
		}
	}
	return left;
}

int main_()
{
	int n;
	cin >> n;
	vector<int>nums(n,0);
	vector<int>dp; // 用来存放最长上升子序列
	// 初始化输入数组
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	//for (int i = 0; i < n; i++)
	//{
	//	int j = lower_bound(dp, nums[i]);
	//	if (j == dp.size())
	//	{
	//		// 代表当前元素不在最长的递增子序列中
	//		// 直接加入该元素
	//		dp.push_back(nums[i]);
	//	}
	//	// 在排序数组中找到了第一个大于他的元素，所以替换该值
	//	else {
	//		dp[j] = nums[i];
	//	}
	//}


	////////////////////////
	vector<int>arr;  //最长上升子序列
	arr.push_back(nums[0]);  //子序列初始化
	for (int i = 1; i < n; i++) {
		if (nums[i] > arr.back()) {  //如果当前元素大于子序列中的最后一个元素，则把当前元素加入子序列中
			arr.push_back(nums[i]);
		}
		else {
			int l = 0, r = arr.size() - 1;
			while (l < r) {  //找到第一个>=w[i]的位置
				int mid = l + r >> 1;
				if (arr[mid] >=nums[i])r = mid;
				else l = mid + 1;
			}
			arr[l] = nums[i];
		}
	}
	for (int num : arr)
	{
		cout << num << ' ';
	}
	return 0;
}