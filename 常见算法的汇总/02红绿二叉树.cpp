//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
static const int N = 1E5 + 10;
static int n, w[N], f[N], x;
static vector<int>g[N];
int calculate(int a, int b, int op)
{
    if (op == 1)return a + b;
    return a ^ b;
}
static void dfs(int u)
{
    //�ߵ�Ҷ�ӽڵ�,Ҳ����g[u].empty(),��ȻҲ������size��������ʵ��
    /*if (!g[u].size()) 
    {
        f[u] = 1;
        return;
    }*/
    if (g[u].empty())
    {
        f[u] = 1;
        return;
    }
    vector<int>v;
    for (int& x : g[u])
    {
        dfs(x);
        v.push_back(f[x]);
    }
    if (v.size() == 1)f[u] = v[0];  //ֻ��һ���ӽڵ�
    if (v.size() == 2)f[u] = calculate(v[0], v[1], w[u]);  //�������ӽڵ㣬������ɫ���м���
}
int main_tree02()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        g[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)cin >> w[i];
    dfs(1);
    cout << f[1] << endl;
    return 0;
}
