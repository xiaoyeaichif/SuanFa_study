#include<iostream>
#include<vector>


using namespace std;
static const int N = 1E5 + 10;
static int tr[N], n, m, a[N];
static int lowbit(int x) {    //������һλ1��λ��
    return x & -x;
}
static void add(int x, int d) {   //�ڵ�xλ����+d
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += d;
}
static long long query(int x) {  //��1~x�ĺ�(ǰ׺��)
    long long ans = 0; //��long long��ʡ�ı�int
    for (int i = x; i; i -= lowbit(i)) ans += tr[i];
    return ans;
}

int main_shuzahung03() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long cnt = 0;  //����Ը���
    for (int i = n - 1; i >= 0; i--) {
        int num = query(a[i] - 1);  //��ѯ��a[i]С��Ԫ������
        cnt += num;
        cout << num << ' ';
        add(a[i], 1);  //����ǰԪ����ӵ���״������
    }
    cout << cnt << endl;
    return 0;
}