#include<iostream>
#include<vector>


using namespace std;
static const int N = 1E5 + 10;
static int tr[N], n, m, a[N];
static int lowbit(int x) {    //算出最后一位1的位置
    return x & -x;
}
static void add(int x, int d) {   //在第x位置上+d
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += d;
}
static long long query(int x) {  //求1~x的和(前缀和)
    long long ans = 0; //开long long，省的爆int
    for (int i = x; i; i -= lowbit(i)) ans += tr[i];
    return ans;
}

int main_shuzahung03() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long cnt = 0;  //逆序对个数
    for (int i = n - 1; i >= 0; i--) {
        int num = query(a[i] - 1);  //查询比a[i]小的元素数量
        cnt += num;
        cout << num << ' ';
        add(a[i], 1);  //将当前元素添加到树状数组中
    }
    cout << cnt << endl;
    return 0;
}