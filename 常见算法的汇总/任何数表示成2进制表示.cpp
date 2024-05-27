//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

static int x ;  //
static vector<int>res;  //存储答案数组
static int pow(int a, int p) {  //计算a^p
    int ans = 1;
    for (int i = 1; i <= p; i++) {
        ans *= a;
    }
    return ans;
}
static void dfs(int x) {
    //base case
    if (x == 0) return;
    int p = log(x) / log(2);
    //记录当前值
    //注意val的值永远不可能会比x大,所以跟转为3进制就有区别
    int val = pow(2, p);
    res.push_back(val);  //记录答案
    dfs(x - val);  //继续递归计算

}
int main_dfs02() {
    cin >> x;
    dfs(x);
    int n = res.size();
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << res[i];  //第一个数字，不需要由加号
        }
        else {
            if (res[i] > 0)cout << "+";
            cout << res[i];
        }
    }
    return 0;
}