#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

static const int N = 1e4 + 10;
static int n; // ��������
static int cost[N]; // ÿ������Ļ���ʱ��
static int d[N], f[N]; // d[]��������飬f[]����¼ÿ��������������ʱ��
static vector<int>e[N]; // �ڽӱ���ʾ����֮���������ϵ
static char s[N]; // ��ʱ�ַ���������

void task(int id)
{
	string str;
	getline(cin, str);
	// ��ҪĿ������������
	if (str.size() == 0)
	{
		getline(cin, str);
	}
	// ��ĩβ���һ���ո��Լ򻯽����߼�
	str += " ";
	int number = 0;  // ������������
	int op = 1; // ��������Ƿ�Ϊ������1 ��ʾ������-1 ��ʾ����
	// ���߼�
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			number = number * op;
			// ��ʾ������
			if (number != -1)
			{
				d[id]++;
				e[number].push_back(id);
			}
			// ���¼���, ��ʾ������
			number = 0;
			op = 1;
		}
		// ��ȡ������
		else if (str[i] == '-')
		{
			op = -1;
		}
		// ���������ַ�
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

// ������
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
	// ����������߼�
	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)  // ������� i �����Ϊ 0
		{
			q.push(i);
			f[i] = cost[i]; // ���� i ���������ʱ��Ϊ������ʱ��
		}
	}
	// �洢���������������ʱ��
	int ans = 0;
	while (!q.empty())
	{
		int x = q.front();
		// ���µ�ǰ������ʱ��
		// ��ǰ����Сֵ
		ans = max(ans, f[x]);
		q.pop();

		// ����Ԫ��
		for (auto& y : e[x])
		{
			// �������� y ���������ʱ��
			f[y] = max(f[y], f[x] + cost[y]);
			d[y]--; // �������
			if (d[y] == 0) // �����Ϊ0�ķŽ�������
			{
				q.push(y);
			}
		}
	}
	cout << ans;
	return 0;
}