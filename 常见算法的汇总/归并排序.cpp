#include <iostream>
#include <string>
#include<vector>

using namespace std;

// �ҵ��м�Ԫ��
static void merge(vector<int>& nums, int left,int mid, int right)
{
	// ����һ������������Ԫ��
	// ��벿����ʼ����
	int i = left;
	// �Ұ벿����ʼ����
	int j = mid + 1;
	// ��ʾԭ�������ʼλ��
	int k = left; 
	vector<int>temp(nums.size());// ------------->ÿ�δ�������Ҫ��������䣬�пռ��˷ѣ���������һ��ȫ�ֿռ�
	// ����������������д��temp����
	while (i <= mid && j <= right)
	{
		// �������������
		if (nums[i] <= nums[j])
		{
			temp[k++] = nums[i++];
		}
		else {
			temp[k++] = nums[j++];
		}
	}
	// ����Ƿ���������ǰ�˳�
	while (i <= mid)
	{
		temp[k++] = nums[i++];
	}
	//
	while (j <= right)
	{
		temp[k++] = nums[j++];
	}
	// ������ˢ�µ�ԭ����������
	for (int t = left; t <= right; t++)
	{
		nums[t] = temp[t];
	}
}

// �鲢��ʵ��
// �ݹ�ʵ��
// ����һ��Ԫ��ʼ��������ķ�ʽ���
void mergeSort(vector<int>& nums, int left, int right)
{
	// �߽�����
	if (left >= right) return;
	// �ݹ����
	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	// �ϲ�һ��������
	merge(nums, left, mid, right);
}



int main_mergeSort()
{
	vector<int>nums = { 1,2,3,4,2,7,5,3,2,1,5,8,9,-5,6,8,9 };
	cout << "-------------��������֮ǰ-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	int size = nums.size();
	mergeSort(nums, 0, size - 1);
	cout << "-------------��������֮��-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	return 0;
}