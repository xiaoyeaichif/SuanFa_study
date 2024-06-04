#include<iostream>
#include<vector>
using namespace std;

static const int N = 50;
static char nums[N][N];
static int n, m;
static void dfs(int i, int j, char x)
{
	if (i < 0 || j < 0 || i >= n || j >= m) return;
	if (nums[i][j] != x)
	{
		return;
	}
	nums[i][j] = '#';//把所有字符改成#
	//上下左右遍历
	dfs(i - 1, j, x);
	dfs(i + 1, j, x);
	dfs(i, j - 1, x);
	dfs(i, j + 1, x);
}
//将统计个数的操作封装成一个函数
int Get_count()
{
	int count_R = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (nums[i][j] == 'R')
			{
				count_R++;
				dfs(i, j, nums[i][j]);
			}
		}
	}
	return count_R;
}
//恢复函数
void rescue()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (nums[i][j] == '#')
			{
				nums[i][j] = 'R';
			}
		}
	}
}

int main_04_01()
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

	vector<vector<int>>ans(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char temp = nums[i][j];
			nums[i][j] = 'W';
			//恢复原来的颜色
			rescue();
			//获取连通块个数
			int count_R = Get_count();
			ans[i][j] = count_R;
			nums[i][j] = temp;

		}
	}
	//答案数组的变化
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	//
	cout << "原数组的变化:" << endl;
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