#include<iostream>

using namespace std;

static const int N = 1010;
char nums[N][N];
static int n, m;
static void dfs(int i,int j,char x)
{
	if (i < 0 || j < 0 || i >= n || j >= m) return;
	// �뵱ǰ�ַ���ͬ������
	if (nums[i][j] != x )
	{
		return;
	}
	// ����һ����־λ
	// ��ʾ������
	nums[i][j] = '#';//������c�ַ��ĳ�#
	//�������ұ���
	dfs(i - 1, j, x);
	dfs(i + 1, j, x);
	dfs(i, j - 1, x);
	dfs(i, j + 1, x);
}



int main_RGB03()
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
	//��¼������ɫ���ֵĴ���
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
	

	//������#�ַ�����Ϊ*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			nums[i][j] = '*';
		}
	}
	//ͳ������*���ֵĴ���,����GB����һ����ֵĴ���

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