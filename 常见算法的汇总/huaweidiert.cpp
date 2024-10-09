#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

const int N = 1e4 + 10;
int n;
int cost[N];
int d[N], f[N];
vector<int>e[N];
char s[N];

void task(int id)
{
	string str;
	getline(cin, str);
	if (str.size() == 0)
	{
		getline(cin, str);
	}
	// 计数
	str += " ";
	int number = 0; 
	int op = 1;
	// 主逻辑
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			number = number * op;
			if (number != -1)
			{
				d[id]++;
				e[number].push_back(id);
			}
			// 重新计算
			number = 0;
			op = 1;
		}
		// 读取到负号
		else if (str[i] == '-')
		{
			op = -1;
		}
		else {
			number = number * 10 + (str[i] - '0');
		}
	}
	/*number = number * op;
	if (number != -1)
	{
		d[id]++;
		e[number].push_back(id);
	}*/
}

// 主函数
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}
	for (int i = 1; i <= n; i++)
	{
		task(i);
	}
	// 拓扑排序的逻辑
	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
		{
			q.push(i);
			f[i] = cost[i];
		}
	}
	// 
	int ans = 0;
	while (!q.empty())
	{
		int x = q.front();
		ans = max(ans, f[x]);
		q.pop();

		// 增加元素
		for (auto& y : e[x])
		{
			f[y] = max(f[y], f[x] + cost[y]);
			d[y]--;
			if (d[y] == 0)
			{
				q.push(y);
			}
		}
	}
	cout << ans;
	return 0;
}