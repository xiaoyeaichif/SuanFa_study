#include<iostream>

using namespace std;

static const int N = 1010;
char nums[N][N];
static int n, m;
static void dfs(int i,int j,char x)
{
	if (i < 0 || j < 0 || i >= n || j >= m) return;
	// 与当前字符不同，跳过
	if (nums[i][j] != x )
	{
		return;
	}
	// 设置一个标志位
	// 表示遍历过
	nums[i][j] = '#';//把所有c字符改成#
	//上下左右遍历
	dfs(i - 1, j, x);
	dfs(i + 1, j, x);
	dfs(i, j - 1, x);
	dfs(i, j + 1, x);
}



int main_RGB03()
{
	
	//n行 m列
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> nums[i][j];
		}
	}
	//记录给定颜色出现的次数
	int count_G = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (nums[i][j] == 'G')
			{
				count_G++;
				dfs(i, j, nums[i][j]);
			}
		}
	}
	cout << count_G << endl;
	int count_B = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (nums[i][j] == 'B')
			{
				count_B++;
				dfs(i, j, nums[i][j]);
			}
		}
	}
	cout << count_B << endl;
	

	//把所有#字符更新为*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			nums[i][j] = '*';
		}
	}
	//统计所有*出现的次数,就是GB和在一起出现的次数

	int count_GB = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (nums[i][j] == '*')
			{
				count_GB++;
				dfs(i, j, nums[i][j]);
			}
		}
	}
	cout << count_GB << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << nums[i][j] << ' ';
		}
		cout << endl;
	}

	
	return 0;
}