#include<iostream>
#include<vector>

using namespace std;

//������ֻ����1���Լ���������
bool isPrime(int num)
{
	//1:num <= 1 �϶���������
	if (num <= 1)
	{
		return false;
	}
	//2��һ������
	if (num == 2) return true;
	//����2�����ż������������
	if (num % 2 == 0) return false;
	//���ڴ���2����������Ƿ�����κ�С����ƽ��������������������
	// �������������������ô���Ǻ�����������������
	int sqRoot = static_cast<int>(std::sqrt(num));
	for (int i = 3; i <= sqRoot; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

//�ڶ���д��
bool isPrime1(int num)
{
	//1:num <= 1 �϶���������
	if (num <= 1)
	{
		return false;
	}
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0) return false;//����Ͳ�������
	}
	//�����Ϊ����
	return true;
}




// �ж��Ƿ�Ϊ����
bool isComposite(int num) {
	return num > 1 && !isPrime(num);
}

int main_zhishu()
{
	int n;
	cin >> n;
	vector<int>nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (isPrime1(nums[i]))
		{
			cout << nums[i]<< "��һ������"<< endl;
		}
		else {
			cout <<nums[i]<< "��һ������"<<endl;
		}
	}
	return 0;
}