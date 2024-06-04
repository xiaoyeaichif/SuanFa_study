//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
static const int N = 1E5 + 10;
static vector<int>g[N];  //��ӱ��vectorд�� �������ڵ�Ȩ��ͼ
static int w[N];    //w[i]��¼��iΪ���ڵ�������еĽڵ�����
static int dfs(int u, int fa) //���������ͼ �Ͳ���Ҫfa�������
{
    w[u] = 1;  //��������һ���ڵ�
    for (int& x : g[u]) //����u�����нڵ�
    {
        if (x == fa)continue; //����߲���Ҫ��һ�� ��֤ÿ���ڵ�ֻ�ᱻ����һ��(�����Ŀ���ֱ�ӱ���)
        w[u] += dfs(x, u);
    }
    return w[u];
}

int main_tree01() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);  //a->b����һ����
        g[b].push_back(a);   //b->a����һ����
    }
    dfs(1, 0);  //�Ӹ��ڵ㿪ʼ���Զ���������,��1Ϊ���ڵ�
    for (int i = 1; i <= n; i++) {
        cout << w[i] << " ";
    }
    return 0;
}