//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


static int n, w[20], k;
static bool isPrime(int x) {  //�ж�����x�Ƿ�Ϊ���� ���Ӷ�ΪO(sqrt(x))
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)return false;  //�г���1��x��������ӣ���������
    }
    return true;
}
int main_left() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> w[i];
    int res = 0;  //����Ȩֵ
    for (int state = 1; state < (1 << n); state++) {  //ö��1~2^n-1������״̬
        long long total = 0;   //�Ӽ�Ԫ�غ�
        int cnt = 0;          //�Ӽ�Ԫ������
        for (int i = 0; i < n; i++) {  //�ж�����w[i]�Ƿ�ѡ��
            if (state >> i & 1) {  //�������w[i]��ѡ��
                total += w[i];
                cnt++;
            }
        }
        if (cnt == k && isPrime(total))res++;  //ѡ��k�����֣����������ܺ�������
    }
    cout << res << endl;
    return 0;
}