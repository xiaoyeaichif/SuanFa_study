#include<iostream>
#include<vector>
using namespace std;

static const int N = 100000 + 5;
//将数组分为三个部分

/*
   0->i-1
   i->i+1
   i+2->n-1
*/
//后缀最小值
vector<int>hou_zui_min(N, INT_MAX);
//后缀最大值
vector<int>hou_zui_max(N, 0);
//
vector<int>w(N, 0);
int main_hebing01()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> w[i];
    //就不用处理i = 0 这个元素,直接让数组移动一个位置
    // for(int i = n;i >= 1;i--)
    // {
    //     hou_zui_max[i] = max(w[i],hou_zui_max[i+1]);
    //     hou_zui_min[i] = min(w[i],hou_zui_min[i+1]);
    // }
    hou_zui_max[n] = w[n];
    hou_zui_min[n] = w[n];
    for (int i = n - 1; i >= 1; i--) {
        hou_zui_max[i] = max(w[i], hou_zui_max[i + 1]);
        hou_zui_min[i] = min(w[i], hou_zui_min[i + 1]);
    }

    //前缀的最大值与最小值
    int pre_max = 0, pre_min = INT_MAX;
    int ans = INT_MAX;

    //遍历当前的元素
    //分别枚举i和i+1，所以数组最多遍历到n-1
    for (int i = 1; i < n; i++)
    {
        int x = w[i] + w[i + 1];
        //如果数组下标大于1,可以更新前缀最大值和最小值
        if (i > 1)
        {
            pre_max = max(pre_max, w[i - 1]);
            pre_min = min(pre_min, w[i - 1]);
        }
        //更新总体的最大值与最小值
        //三个元素去最值要注意加大括号
        //整体的最大值
        int max_val = max({ pre_max,x,hou_zui_max[i + 2] });
        //整体的最小值
        int min_val = min({ pre_min,x,hou_zui_min[i + 2] });
        ans = min(ans, max_val - min_val);
    }
    cout << ans << endl;
    return 0;
}

