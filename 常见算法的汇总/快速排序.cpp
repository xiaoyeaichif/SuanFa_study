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


// �ݹ�ʵ��
void QuickSort(vector<int>& nums, int left, int right)
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
	QuickSort(nums, index + 1, right);
}



// ���ŵĵڶ���д��

int findIndex2(vector<int>& nums, int left, int right) {
	// ѡ��궨Ԫ��Ϊ�����Ԫ�أ���������ֵ
	int temp = nums[left];
	int start = left, end = right;

	while (start < end) {
		// ���Ҳ��ҵ���һ��С�ڱ궨Ԫ�ص�Ԫ��
		while (start < end && nums[end] >= temp) {
			end--;
		}
		// ������ҵ���һ�����ڱ궨Ԫ�ص�Ԫ��
		while (start < end && nums[start] <= temp) {
			++start;
		}
		// ���δ������������λ�õ�Ԫ��
		if (start < end) {
			swap(nums[start], nums[end]);
		}
	}

	// ���궨Ԫ�ؽ���������λ��
	swap(nums[left], nums[start]);
	//nums[start] = temp;


	// ���ر궨Ԫ�ص�����λ��
	return start;
}




// ���õݹ�
void QuickSort2(vector<int>& nums, int left, int right)
{
	// base case
	if (left >= right) return;

	int mid = findIndex2(nums, left, right);
	// ���
	QuickSort2(nums, left, mid - 1);
	// �ұ�
	QuickSort2(nums, mid + 1, right);
}








// ���������ʵ��



int main()
{
	vector<int>nums = { 3, -6, 8, 10, -1, 2, 1, -6 };
	cout << "-------------��������֮ǰ-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	int size = nums.size();
	QuickSort2(nums, 0, size - 1);
	cout << "-------------��������֮��-------------" << endl;
	for (int& num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	return 0;
}