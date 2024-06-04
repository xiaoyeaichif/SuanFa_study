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
	nums[i][j] = '#';//�������ַ��ĳ�#
	//�������ұ���
	dfs(i - 1, j, x);
	dfs(i + 1, j, x);
	dfs(i, j - 1, x);
	dfs(i, j + 1, x);
}
//��ͳ�Ƹ����Ĳ�����װ��һ������
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
//�ָ�����
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

	//n�� m��
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
			//�ָ�ԭ������ɫ
			rescue();
			//��ȡ��ͨ�����
			int count_R = Get_count();
			ans[i][j] = count_R;
			nums[i][j] = temp;

		}
	}
	//������ı仯
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	//
	cout << "ԭ����ı仯:" << endl;
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