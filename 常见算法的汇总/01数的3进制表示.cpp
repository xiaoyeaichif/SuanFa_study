//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

static int x, flag;  //flag�����жϵ�ǰ��3���������Ǹ�
static vector<int>res;  //�洢������
int pow(int a, int p) {  //����a^p
    int ans = 1;
    for (int i = 1; i <= p; i++) {
        ans *= a;
    }
    return ans;
}
void dfs(int x) {
    if (x <= 1) {  //�ݹ麯����������
        if (x == 1)res.push_back(x * flag);
        return;
    }
    int p = log(x) / log(3);
    int total = (pow(3, p + 1) - 1) / 2;
    if (total >= x) {  //���������ɸ�3���ݴι��ɣ�ֱ�ӵݹ���㼴��
        int val = pow(3, p);
        res.push_back(val * flag);  //��¼��
        dfs(x - val);  //�����ݹ����
    }
    else {   //������1 3 ... 3^p ��ʾ ��Ҫ���Ͻ�λ
        int val = pow(3, p + 1);
        res.push_back(val * flag);
        flag *= -1;  //��λ�������Ҫ�任����λ
        x = val - x;  //��������ʣ�µ�x
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
            cout << res[i];  //��һ�����֣�����Ҫ�ɼӺ�
        }
        else {
            if (res[i] > 0)cout << "+";
            cout << res[i];
        }
    }
    return 0;
}