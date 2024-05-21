#include<iostream>
#include<vector>

using namespace std;
static int n,m;
static const int N = 100000 + 10;
vector<int>tree(N);
//树状数组涉及的函数
/*
	1:lowbit函数
	2:add函数
	3:qury函数
*/

//获取数组最右侧的1
int lowbit(int x)
{
	return x & -x;
}

//给定位置的相加一个值
void add(int x,int value)
{
	for (int i = x; i <= n; i += lowbit(i))
	{
		tree[i] += value;
	}
}

//查询前缀[1...x]之间的和
long long qury(int x)
{
	long long ans = 0;
	while (x > 0)
	{
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}

//主函数的实现
int main_shuzhuan01()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		add(i, x);//初始化
	}
	for (int i = 0; i < m; i++)
	{
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1)//单点修改
		{
			add(x, y);
		}
		else {
			cout << qury(y) - qury(x - 1) << endl;
		}
	}
	return 0;
}