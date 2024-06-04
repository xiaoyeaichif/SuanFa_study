#include<iostream>

using namespace std;

int get_yinzi(int x)
{
	int ans = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0) // x能整除i,那么i是x的因子
		{
			ans += 1;
		}
	}
	return ans;
}

int main_yinzi05()
{
	int cnt_max = 0;//统计在给定数的范围内因子个数的最大值
	for (int i = 1; i <= 8; i++)
	{
		cnt_max = max(cnt_max, get_yinzi(i));
	}
	cout << cnt_max << endl;
	return 0;
}