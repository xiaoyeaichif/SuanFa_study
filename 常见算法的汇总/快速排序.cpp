#include <iostream>
#include <string>
#include<vector>

using namespace std;

// �ҵ��м�Ԫ��
int findIndex(vector<int>& nums, int left, int right)
{
	int start = left;
	int end = right;
	// ѡ���һ��Ԫ����Ϊ֧��
	int temp = nums[left];
	// ���ŵ�ģ��
	// left == right ����ѭ��
	// ��ҪĿ���ǰɴ���temp��Ԫ���Ƶ��Ҳ�
	// С��temp���ƶ������
	while (left < right)
	{
		// ��Ԫ�ط���temp���ұ�
		while (left < right && nums[right] >= temp)
		{
			right--;
		}
		// ��ѭ�����ҵ���ǰ��Ԫ�� < temp������ǰ��Ԫ�ط���left��λ����
		nums[left] = nums[right];
		// ͬ��
		// ��ʼ��������Ԫ��
		while (left < right && nums[left] <= temp)
		{
			left++;
		}
		// �ҵ���һ����temp���Ԫ��
		// �����ƶ����Ҳ�
		nums[right] = nums[left];
	}
	// ��ѭ��
	// left == right
	nums[left] = temp;
	// �ҵ���Ԫ�ؽ������Ϊ��������
	return left; // ����return right��һ��
	
}

// ���������ʵ��
// �ݹ�ʵ��
void QuickSort(vector<int>&nums,int left ,int right)
{
	// һ����ȣ����̷���
	if (left >= right)
	{
		return;
	}
	// �ݹ����
	// �ҵ��м���λ��
	int index = findIndex(nums, left, right);
	// ��ߵݹ�
	QuickSort(nums, left, index - 1);
	// �ұߵݹ�
	QuickSort(nums, index + 1,right);
}



int main_Quicksort()
{
	vector<int>nums = { 1,2,3,4,2,7,5,3,2,1,5,8,9,-5,6,8,9 };
	cout << "-------------��������֮ǰ-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	int size = nums.size();
	QuickSort(nums, 0, size - 1);
	cout << "-------------��������֮��-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	return 0;
}