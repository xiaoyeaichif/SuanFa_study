//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


static int n, w[20], k;
static bool isPrime(int x) {  //判断数字x是否为质数 复杂度为O(sqrt(x))
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)return false;  //有除了1和x以外的因子，则不是质数
    }
    return true;
}
int main_left() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> w[i];
    int res = 0;  //数组权值
    for (int state = 1; state < (1 << n); state++) {  //枚举1~2^n-1的所有状态
        long long total = 0;   //子集元素和
        int cnt = 0;          //子集元素数量
        for (int i = 0; i < n; i++) {  //判断数字w[i]是否被选择
            if (state >> i & 1) {  //如果数字w[i]被选择
                total += w[i];
                cnt++;
            }
        }
        if (cnt == k && isPrime(total))res++;  //选了k个数字，并且数字总和是质数
    }
    cout << res << endl;
    return 0;
}