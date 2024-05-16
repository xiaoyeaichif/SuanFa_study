#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

static const int N = 1010;
static int Father[N], Count[N];
//并查集的初始化
static void build(int n)
{
    for (int i = 1; i <= n; i++)
    {
        Father[i] = i;
    }
}

//Find函数的实现
static int Find(int x)
{
    if (Father[x] != x)
    {
        Father[x] = Find(Father[x]);//路径压缩
    }
    return Father[x];
}
//联合函数的实现
//判断两个集合是否是一个集合,如果不是则合并
static void Union(int x, int y, int w)
{
    int root_x = Find(x);
    int root_y = Find(y);
    //始终让根节点相加
    Count[root_y] += w;
    if (root_x != root_y)
    {
        //更新相似度
        //也就是将x连接在y上,所以需要把x的信息都给y
        Count[root_y] += Count[root_x];
        Father[root_x] = root_y;
    }

}

//主函数的实现
int main_bincha04()
{
    int n;
    //构建并查集
    cin >> n;
    build(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x > 0)
            {
                Union(i, j, x);
            }
        }
    }
    vector<int>ans;//统计满足相似度的个数
    for (int i = 1; i <= n; i++)
    {
        if (Find(i) == i) //找到根节点对应的值
        {
            ans.push_back(Count[i] / 2);
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    for (int& x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << Count[i] << ' ';
    }
    return 0;

}
