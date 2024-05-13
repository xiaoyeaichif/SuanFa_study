#include<iostream>
#include<vector>
using namespace std;

//��������ʽ
int lower_bound1(vector<int>& nums, int target)
{
	int N = nums.size();
	int left = 0;
	int right = N - 1;
	while (left <= right) //����left = right + 1
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

//����ҿ�������ʽ
int lower_bound2(vector<int>& nums, int target)
{
	int N = nums.size();
	int left = 0;
	int right = N ;
	while (left < right) //����left == right �˳�
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
	cout << "��������ʽ: " << lower_bound1(nums, target) << endl;
	cout << "����ҿ�������ʽ: " << lower_bound2(nums, target) << endl;
	return 0;
}