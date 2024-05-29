//#include<bits/stdc++.h>
#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
static const int N = 10;
static int n, m, g[N][N];
int main_DFS04() {
    unordered_map<int, unordered_set<int>>mp;  //记录周一到周日那些车不可以开
    for (int i = 0; i < 7; i++) {
        int t, x;
        scanf("%d ", &t);
        while (t--) {
            scanf("%d ", &x);
            mp[i].insert(x);
        }
    }
    int res = 11;  //求所需要车辆的最小值
    for (int state = 1; state < (1 << 10); state++) {
        bool flag = true;  //检查当前状态是否合法
        for (int i = 0; i < 7; i++) {
            bool f1 = false;  //检查当前天是否合法
            for (int j = 0; j < 10; j++) {
                if (state >> j & 1 && (!mp[i].count(j))) {   //购买了尾号为j的车，且当天尾号为j的车子可以出行
                    f1 = true;
                }
            }
            if (!f1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int cnt = 0;  //统计state状态下购买车的数量
            for (int i = 0; i < 10; i++) {
                if (state >> i & 1) {
                    cnt++;
                }
            }
            res = min(res, cnt);  //更新res最小值
        }
    }
    if (res == 11) {
        puts("-1");
    }
    else {
        cout << res << endl;
    }
    return 0;
}