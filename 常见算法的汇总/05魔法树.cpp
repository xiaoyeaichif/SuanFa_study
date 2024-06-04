#include<iostream>
#include<vector>
#include<string>
using namespace std;
static const int N = 1010;
static long long n, r, l;
static string s;
static vector<int>g[N];
static long long res;
static void dfs(int u, int fa, long long total)   //ö����uΪ�յ��·��
{
    total = total * 2 + (s[u] - '0');
    if (total > 1e18)return; //��ֹ��long long
    if (fa != -1)   //˵��·����������Ϊ1
    {
        if (total >= l && total <= r)res++;
    }
    for (int& x : g[u])
    {
        if (x == fa)continue;  //�����
        dfs(x, u, total);   //������������·��
    }
}

int main()
{
    cin >> n >> l >> r;
    cin >> s;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //���������ӽڵ�
    //ʹ�ý���ֵ���������ƶ�һ����λ,���Ժͽ����±����ö�Ӧ��
    s = ' ' + s;
    for (int i = 1; i <= n; i++)  //��ÿһ������һ��DFS��ö����iΪ����·��
    {
        dfs(i, -1, 0);
    }
    cout << res << endl;
    return 0;
}
