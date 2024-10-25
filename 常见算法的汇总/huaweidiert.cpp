#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

static const int N = 1e4 + 10;
static int n; // 任务数量
static int cost[N]; // 每个任务的花费时间
static int d[N], f[N]; // d[]：入度数组，f[]：记录每个任务的最早完成时间
static vector<int>e[N]; // 邻接表，表示任务之间的依赖关系
static char s[N]; // 临时字符串缓冲区

void task(int id)
{
	string str;
	getline(cin, str);
	// 主要目的是跳过空行
	if (str.size() == 0)
	{
		getline(cin, str);
	}
	// 在末尾添加一个空格以简化解析逻辑
	str += " ";
	int number = 0;  // 解析出的数字
	int op = 1; // 标记数字是否为负数，1 表示正数，-1 表示负数
	// 主逻辑
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			number = number * op;
			// 表示有依赖
			if (number != -1)
			{
				d[id]++;
				e[number].push_back(id);
			}
			// 重新计算, 表示无依赖
			number = 0;
			op = 1;
		}
		// 读取到负号
		else if (str[i] == '-')
		{
			op = -1;
		}
		// 解析数字字符
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
int main_huawei02()
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
		if (d[i] == 0)  // 如果任务 i 的入度为 0
		{
			q.push(i);
			f[i] = cost[i]; // 任务 i 的最早完成时间为其自身时间
		}
	}
	// 存储所有任务的最大完成时间
	int ans = 0;
	while (!q.empty())
	{
		int x = q.front();
		// 更新当前最大完成时间
		// 当前的最小值
		ans = max(ans, f[x]);
		q.pop();

		// 增加元素
		for (auto& y : e[x])
		{
			// 更新任务 y 的最早完成时间
			f[y] = max(f[y], f[x] + cost[y]);
			d[y]--; // 减少入度
			if (d[y] == 0) // 将入度为0的放进队列中
			{
				q.push(y);
			}
		}
	}
	cout << ans;
	return 0;
}