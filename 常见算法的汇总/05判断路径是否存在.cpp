


/*
    其实就是并查集，检查元素是不是在同一个集合问题

    并查集包含的函数Find，Union，isSame
*/

#include<iostream>
#include<vector>
using namespace std;
static const int N = 110;
static vector<int>Father(N, 0);
static int n, m;

void build()
{
    for (int i = 1; i <= n; i++)
    {
        Father[i] = i;
    }
}

//查找函数的写法,需要递归压缩
int Find(int val)
{
    if (Father[val] != val)
    {
        Father[val] = Find(Father[val]);
    }
    return Father[val];
}

void Union(int x, int y)
{
    int root_x = Find(x);
    int root_y = Find(y);
    if (root_x != root_y)
    {
        Father[root_x] = root_y;
    }
}

bool isSame(int x, int y)
{
    return Find(x) == Find(y);
}

//主函数的实现

int main_bincha05()
{
    cin >> n>>m;
    build(); // 构建并查集
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    int c, d;
    cin >> c >> d;
    bool flag = isSame(c, d);
    if (flag)
    {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}

