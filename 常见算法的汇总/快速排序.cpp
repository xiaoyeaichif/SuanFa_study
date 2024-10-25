#include <iostream>
#include <string>
#include<vector>

using namespace std;

// 找到中间元素
int findIndex(vector<int>& nums, int left, int right)
{
	int start = left;
	int end = right;
	// 选择第一个元素作为支点
	int temp = nums[left];
	// 快排的模板
	// left == right 跳出循环
	while (left < right)
	{
		// 把元素放在temp的右边
		while (left < right && nums[right] >= temp)
		{
			right--;
		}
		// 出循环，找到当前的元素 < temp，将当前的元素放在left的位置上
		nums[left] = nums[right];
		// 开始更新左侧的元素
		while (left < right && nums[left] <= temp)
		{
			left++;
		}
		nums[right] = nums[left];
	}
	// left == right
	nums[left] = temp;
	return left;
}

// 快速排序的实现
void QuickSort(vector<int>&nums,int left ,int right)
{
	// 一旦相等，立刻返回
	if (left >= right)
	{
		return;
	}
	// 递归调用
	// 找到中间点的位置
	int index = findIndex(nums, left, right);
	// 左边递归
	QuickSort(nums, left, index - 1);
	// 右边递归
	QuickSort(nums, index + 1,right);
}



int main()
{
	vector<int>nums = { 1,2,3,4,2,7,5,3,2,1,5,8,9,-5,6,8,9 };
	cout << "-------------快速排序之前-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	int size = nums.size();
	QuickSort(nums, 0, size - 1);
	cout << "-------------快速排序之后-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	return 0;
}