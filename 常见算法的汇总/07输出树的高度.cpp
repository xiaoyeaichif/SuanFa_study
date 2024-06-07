#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static const int N = 1010;
static vector<int> g[N];
//输出树的最大高度
int dfs(int u)
{
	if (g[u].empty())
	{
		return 1;//一旦为空,马上返回
	}
	int max_height = 0;//每一层的初始值应该要设置为0
	for (int& x : g[u])
	{
		//记录每一层的最大值
		max_height = max(max_height, dfs(x));
	}
	return max_height + 1;

}


//主函数
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