#include<iostream>

using namespace std;

int get_yinzi(int x)
{
	int ans = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0) // x������i,��ôi��x������
		{
			ans += 1;
		}
	}
	return ans;
}

int main_yinzi05()
{
	int cnt_max = 0;//ͳ���ڸ������ķ�Χ�����Ӹ��������ֵ
	for (int i = 1; i <= 8; i++)
	{
		cnt_max = max(cnt_max, get_yinzi(i));
	}
	cout << cnt_max << endl;
	return 0;
}