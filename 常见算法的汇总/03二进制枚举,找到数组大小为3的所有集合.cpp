#include<iostream>
#include<vector>
using namespace std;

/*
	输入描述：第一行输入一个整数n,第二行输入n个整数
	输出描述: 找到所有大小为3的子数组,但是数组中不能出现重复元素
*/

vector<vector<int>>ans;
int main_dfs03() {
    int n;
    cin >> n;
    int k = 4;
    int cnt = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 二进制枚举的过程
    for (int state = 1; state < (1 << n); state++) {
        vector<int> res;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if ((state >> i & 1) == 1) {
                res.push_back(nums[i]);
                count++;
            }
        }

        if (count != k)continue;
        ans.push_back(res);
        cnt++;
    }

    for (auto &num : ans) {
        for (auto &a : num) {
            cout << a << ' ';
        }
        cout << endl;
    }
    cout << cnt << endl;
    return 0;
}