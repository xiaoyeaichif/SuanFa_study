//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

static const int N = 5010;
int Father[N];

//并差集的构建
static void build(int n)
{
    for (int i = 1; i <= n; i++)
    {
        Father[i] = i;
    }
}

//Find函数的构建
static int Find(int x)
{
    if (Father[x] != x)
    {
        //路径压缩，递归实现
        Father[x] = Find(Father[x]);
    }
    //表示找到了跟节点
    return Father[x];
}

//is_same函数的构建
//查看两个值是否属于同一个集合
static bool is_Same(int x, int y)
{
    return Find(x) == Find(y);
}

//Union函数的构建
//合并两个集合
//如果两个值来自一个集合,则不需要合并
//如果不是一个集合则需要合并
static void Union(int x, int y)
{
    int root_x = Find(x);
    int root_y = Find(y);
    //这里的合并是随意的,但是优化的时候可以
    //让小的集合挂在大的集合上面
    if (root_x != root_y)
    {
        //将x挂在y的集合上
        Father[root_x] = root_y;
    }

}



//主函数的实现
int main_bincha03()
{
    //清空缓存
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;
    //调用初始化函数
    build(n);
    //先执行Union然后在进行判断

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }
    //然后执行判断是否在一个集合
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