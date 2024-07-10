

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
			right = mid - 1; // ����࿿���ҵ������������Ԫ���±�
		}
	}
	return left;
}

int main_()
{
	int n;
	cin >> n;
	vector<int>nums(n,0);
	vector<int>dp; // ������������������
	// ��ʼ����������
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	//for (int i = 0; i < n; i++)
	//{
	//	int j = lower_bound(dp, nums[i]);
	//	if (j == dp.size())
	//	{
	//		// ����ǰԪ�ز�����ĵ�����������
	//		// ֱ�Ӽ����Ԫ��
	//		dp.push_back(nums[i]);
	//	}
	//	// �������������ҵ��˵�һ����������Ԫ�أ������滻��ֵ
	//	else {
	//		dp[j] = nums[i];
	//	}
	//}


	////////////////////////
	vector<int>arr;  //�����������
	arr.push_back(nums[0]);  //�����г�ʼ��
	for (int i = 1; i < n; i++) {
		if (nums[i] > arr.back()) {  //�����ǰԪ�ش����������е����һ��Ԫ�أ���ѵ�ǰԪ�ؼ�����������
			arr.push_back(nums[i]);
		}
		else {
			int l = 0, r = arr.size() - 1;
			while (l < r) {  //�ҵ���һ��>=w[i]��λ��
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