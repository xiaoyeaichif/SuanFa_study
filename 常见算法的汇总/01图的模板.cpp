//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


const int N = 1E5 + 10;
vector<int>g[N];  //��ӱ��vectorд�� �������ڵ�Ȩ��ͼ
int w[N]; // �洢ÿ���ڵ��Ȩֵ
void dfs(int u, int fa) //���������ͼ �Ͳ���Ҫfa�������
{
    //do things
    for (int& x : g[u]) //����u�����нڵ�
    {
        if (x == fa)continue; //����߲���Ҫ��һ�� ��֤ÿ���ڵ�ֻ�ᱻ����һ��(�����Ŀ���ֱ�ӱ���)
        dfs(x, u);
        // do things��// �������������������߼�����Խڵ�Ĳ���
    }
}

int main_garph01() {
    int n, m;  //n����,m����
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);  //a->b����һ����
    }
    // ����ÿ���ڵ��Ȩֵ
    //Ȩֵ�ǹ涨��
    for (int i = 1; i <= n; i++)cin >> w[i];



    return 0;
}
