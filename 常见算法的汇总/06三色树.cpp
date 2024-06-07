#include<iostream>
#include<string>
#include<vector>
using namespace std;


static const int N = 1E5 + 10;
static vector<int>g[N];  //领接表的vector写法 仅适用于点权建图
static int f[N][3];    //f[i][0/1/2]表示以i为根节点的子树中R、G、B三种颜色的节点数量
static int n;
static int total[3];  //整棵树的R、G、B的三种颜色的数量
static string s;
static int res = 0;  //方案数
static vector<int> dfs(int u, int fa) //返回以u为根节点的子树乘积中因子R,G,B的个数
{
    //检查当前的u作为根结点的对应的R,G,B个数
    //要注意的是u是从1开始的,而字符串的下标是从0开始的,需要减1
    if (s[u - 1] == 'R') f[u][0] += 1;
    else if (s[u - 1] == 'G') f[u][1] += 1;
    else {
        f[u][2] += 1;
    }
    for (auto& x : g[u])
    {
        if (x == fa) continue;//遍历到父节点,直接跳过
        //继续递归
        vector<int>son = dfs(x, u);
        for (int i = 0; i < 3; i++)
        {
            //跟结点的颜色与子节点的颜色对应相加
            /*
                f[u][0]--->对应son[0]的红色
                f[u][1]--->对应son[1]的绿色
                f[u][2]--->对应son[2]的蓝色
            */
            f[u][i] += son[i];
        }
    }
    /*
         判断当前的结点u组成的子树能否满足题意,
         也就是分割成两棵树,并且都是多彩的.
         也就是总颜色数量减去当前树的数量还能维持为一个新的
         多彩树
    */
    if (f[u][0] >= 1 && f[u][1] >= 1 && f[u][2] >= 1
        && total[0] - f[u][0] > 0
        && total[1] - f[u][1] > 0
        && total[2] - f[u][2] > 0)
        res += 1;
    //返回结点u为根节点的时的子树颜色
    return { f[u][0],f[u][1],f[u][2] };
}

int main_dfs06() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a;//输入的与下标i对应
        cin >> a;
        g[a].push_back(i);
        g[i].push_back(a);
    }
    cin >> s;//输入字符串颜色
    //统计字符串中三种颜色的个数
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R')total[0]++;
        else if (s[i] == 'B')total[1]++;
        else total[2]++;
    }
    dfs(1, 0);
    cout << res << endl;
    return 0;
}