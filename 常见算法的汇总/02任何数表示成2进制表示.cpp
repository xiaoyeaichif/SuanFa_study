//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

static int x ;  //
static vector<int>res;  //�洢������
static int pow(int a, int p) {  //����a^p
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
    //��¼��ǰֵ
    //ע��val��ֵ��Զ�����ܻ��x��,���Ը�תΪ3���ƾ�������
    int val = pow(2, p);
    res.push_back(val);  //��¼��
    dfs(x - val);  //�����ݹ����

}
int main_dfs02() {
    cin >> x;
    dfs(x);
    int n = res.size();
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