//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

static const int N = 5010;
int Father[N];

//����Ĺ���
static void build(int n)
{
    for (int i = 1; i <= n; i++)
    {
        Father[i] = i;
    }
}

//Find�����Ĺ���
static int Find(int x)
{
    if (Father[x] != x)
    {
        //·��ѹ�����ݹ�ʵ��
        Father[x] = Find(Father[x]);
    }
    //��ʾ�ҵ��˸��ڵ�
    return Father[x];
}

//is_same�����Ĺ���
//�鿴����ֵ�Ƿ�����ͬһ������
static bool is_Same(int x, int y)
{
    return Find(x) == Find(y);
}

//Union�����Ĺ���
//�ϲ���������
//�������ֵ����һ������,����Ҫ�ϲ�
//�������һ����������Ҫ�ϲ�
static void Union(int x, int y)
{
    int root_x = Find(x);
    int root_y = Find(y);
    //����ĺϲ��������,�����Ż���ʱ�����
    //��С�ļ��Ϲ��ڴ�ļ�������
    if (root_x != root_y)
    {
        //��x����y�ļ�����
        Father[root_x] = root_y;
    }

}



//��������ʵ��
int main_bincha03()
{
    //��ջ���
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;
    //���ó�ʼ������
    build(n);
    //��ִ��UnionȻ���ڽ����ж�

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }
    //Ȼ��ִ���ж��Ƿ���һ������
    for (int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        if (is_Same(a, b)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}