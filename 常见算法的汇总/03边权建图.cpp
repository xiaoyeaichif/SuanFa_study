// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


typedef pair<int, int>PII;
#define x first
#define y second
typedef long long ll;
static const int N = 1E5 + 10;
static vector<PII>g[N];
static int n, f[N];


//void dfs(int u, int fa) {
//    for (auto& [x, w] : g[u]) {
//        if (x == fa)continue;
//        dfs(x, u);
//        //�����߼�
//    }
//}
int main_graph03() {
    cin >> n;
    //������Ȩͼ
    //n����,n-1����
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({ b,c });
        g[b].push_back({ a,c });
    }

    //n����,n����
    /*for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({ b,c });
        g[b].push_back({ a,c });
    }*/

    //����ÿ�������ܵ�������ڶ����Լ��ߵ�Ȩֵ
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " neighbors: ";
        //����ÿ����,���ÿ���ߵĹ�ϵͼ
        //edgeΪһ��pair����
        for (auto& edge : g[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
    return 0;
}