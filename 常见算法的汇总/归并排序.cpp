#include <iostream>
#include <string>
#include<vector>

using namespace std;

// 找到中间元素
static void merge(vector<int>& nums, int left,int mid, int right)
{
	// 申请一个数组用来放元素
	// 左半部的起始索引
	int i = left;
	// 右半部的起始索引
	int j = mid + 1;
	// 表示原数组的起始位置
	int k = left; 
	vector<int>temp(nums.size());// ------------->每次创建都需要申请大区间，有空间浪费，可以申请一个全局空间
	// 将左右两部分数据写入temp数组
	while (i <= mid && j <= right)
	{
		// 有序数组的排序
		if (nums[i] <= nums[j])
		{
			temp[k++] = nums[i++];
		}
		else {
			temp[k++] = nums[j++];
		}
	}
	// 检测是否有数组提前退出
	while (i <= mid)
	{
		temp[k++] = nums[i++];
	}
	//
	while (j <= right)
	{
		temp[k++] = nums[j++];
	}
	// 将数据刷新到原来的数组上
	for (int t = left; t <= right; t++)
	{
		nums[t] = temp[t];
	}
}

// 归并的实现
// 递归实现
// 利用一个元素始终是有序的方式解决
void mergeSort(vector<int>& nums, int left, int right)
{
	// 边界条件
	if (left >= right) return;
	// 递归操作
	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	// 合并一整个操作
	merge(nums, left, mid, right);
}



int main_mergeSort()
{
	vector<int>nums = { 1,2,3,4,2,7,5,3,2,1,5,8,9,-5,6,8,9 };
	cout << "-------------快速排序之前-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	int size = nums.size();
	mergeSort(nums, 0, size - 1);
	cout << "-------------快速排序之后-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	return 0;
}