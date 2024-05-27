//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

static int x, flag;  //flag用来判断当前的3次幂是正是负
static vector<int>res;  //存储答案数组
int pow(int a, int p) {  //计算a^p
    int ans = 1;
    for (int i = 1; i <= p; i++) {
        ans *= a;
    }
    return ans;
}
void dfs(int x) {
    if (x <= 1) {  //递归函数结束条件
        if (x == 1)res.push_back(x * flag);
        return;
    }
    int p = log(x) / log(3);
    int total = (pow(3, p + 1) - 1) / 2;
    if (total >= x) {  //可以由若干个3的幂次构成，直接递归计算即可
        int val = pow(3, p);
        res.push_back(val * flag);  //记录答案
        dfs(x - val);  //继续递归计算
    }
    else {   //不能由1 3 ... 3^p 表示 需要向上借位
        int val = pow(3, p + 1);
        res.push_back(val * flag);
        flag *= -1;  //借位，因此需要变换符号位
        x = val - x;  //继续计算剩下的x
        dfs(x);
    }

}
int main_dfs01() {
    cin >> x;
    flag = 1;
    dfs(x);
    int n = res.size();
    cout << log(32) / log(3) << endl;
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