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
	// 主要目的是吧大于temp的元素移到右侧
	// 小于temp的移动到左侧
	while (left < right)
	{
		// 把元素放在temp的右边
		while (left < right && nums[right] >= temp)
		{
			right--;
		}
		// 出循环，找到当前的元素 < temp，将当前的元素放在left的位置上
		nums[left] = nums[right];
		// 同理
		// 开始更新左侧的元素
		while (left < right && nums[left] <= temp)
		{
			left++;
		}
		// 找到第一个比temp大的元素
		// 将其移动到右侧
		nums[right] = nums[left];
	}
	// 出循环
	// left == right
	nums[left] = temp;
	// 找到该元素将数组分为两个区间
	return left; // 或者return right都一样
	
}

// 快速排序的实现
// 递归实现
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



int main_Quicksort()
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