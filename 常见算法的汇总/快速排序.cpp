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


// 递归实现
void QuickSort(vector<int>& nums, int left, int right)
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
	QuickSort(nums, index + 1, right);
}



// 快排的第二种写法

int findIndex2(vector<int>& nums, int left, int right) {
	// 选择标定元素为最左侧元素，并保存其值
	int temp = nums[left];
	int start = left, end = right;

	while (start < end) {
		// 从右侧找到第一个小于标定元素的元素
		while (start < end && nums[end] >= temp) {
			end--;
		}
		// 从左侧找到第一个大于标定元素的元素
		while (start < end && nums[start] <= temp) {
			++start;
		}
		// 如果未交错，交换两个位置的元素
		if (start < end) {
			swap(nums[start], nums[end]);
		}
	}

	// 将标定元素交换到最终位置
	swap(nums[left], nums[start]);
	//nums[start] = temp;


	// 返回标定元素的最终位置
	return start;
}




// 调用递归
void QuickSort2(vector<int>& nums, int left, int right)
{
	// base case
	if (left >= right) return;

	int mid = findIndex2(nums, left, right);
	// 左边
	QuickSort2(nums, left, mid - 1);
	// 右边
	QuickSort2(nums, mid + 1, right);
}








// 快速排序的实现



int main()
{
	vector<int>nums = { 3, -6, 8, 10, -1, 2, 1, -6 };
	cout << "-------------快速排序之前-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	int size = nums.size();
	QuickSort2(nums, 0, size - 1);
	cout << "-------------快速排序之后-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	return 0;
}