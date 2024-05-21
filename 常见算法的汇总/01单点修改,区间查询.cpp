#include<iostream>
#include<vector>

using namespace std;
static int n,m;
static const int N = 100000 + 10;
vector<int>tree(N);
//��״�����漰�ĺ���
/*
	1:lowbit����
	2:add����
	3:qury����
*/

//��ȡ�������Ҳ��1
int lowbit(int x)
{
	return x & -x;
}

//����λ�õ����һ��ֵ
void add(int x,int value)
{
	for (int i = x; i <= n; i += lowbit(i))
	{
		tree[i] += value;
	}
}

//��ѯǰ׺[1...x]֮��ĺ�
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

//��������ʵ��
int main_shuzhuan01()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		add(i, x);//��ʼ��
	}
	for (int i = 0; i < m; i++)
	{
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1)//�����޸�
		{
			add(x, y);
		}
		else {
			cout << qury(y) - qury(x - 1) << endl;
		}
	}
	return 0;
}