#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static const int N = 1010;
static vector<int> g[N];
//����������߶�
int dfs(int u)
{
	if (g[u].empty())
	{
		return 1;//һ��Ϊ��,���Ϸ���
	}
	int max_height = 0;//ÿһ��ĳ�ʼֵӦ��Ҫ����Ϊ0
	for (int& x : g[u])
	{
		//��¼ÿһ������ֵ
		max_height = max(max_height, dfs(x));
	}
	return max_height + 1;

}


//������
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}
	cout << dfs(1) << endl;
	return 0;
}