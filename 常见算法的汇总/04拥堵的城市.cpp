//#include<bits/stdc++.h>
#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
static const int N = 10;
static int n, m, g[N][N];
int main_DFS04() {
    unordered_map<int, unordered_set<int>>mp;  //��¼��һ��������Щ�������Կ�
    for (int i = 0; i < 7; i++) {
        int t, x;
        scanf("%d ", &t);
        while (t--) {
            scanf("%d ", &x);
            mp[i].insert(x);
        }
    }
    int res = 11;  //������Ҫ��������Сֵ
    for (int state = 1; state < (1 << 10); state++) {
        bool flag = true;  //��鵱ǰ״̬�Ƿ�Ϸ�
        for (int i = 0; i < 7; i++) {
            bool f1 = false;  //��鵱ǰ���Ƿ�Ϸ�
            for (int j = 0; j < 10; j++) {
                if (state >> j & 1 && (!mp[i].count(j))) {   //������β��Ϊj�ĳ����ҵ���β��Ϊj�ĳ��ӿ��Գ���
                    f1 = true;
                }
            }
            if (!f1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int cnt = 0;  //ͳ��state״̬�¹��򳵵�����
            for (int i = 0; i < 10; i++) {
                if (state >> i & 1) {
                    cnt++;
                }
            }
            res = min(res, cnt);  //����res��Сֵ
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