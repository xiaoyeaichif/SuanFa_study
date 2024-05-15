//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int MAXN = 1000001;
//
//int father[MAXN];
//int size[MAXN];
//int stack[MAXN]; // ����ջ������·��ѹ��
//
//void build(int n) {
//    for (int i = 1; i <= n; i++) {
//        father[i] = i;
//        size[i] = 1;
//    }
//}
//
//int find(int i) {
//    int idx = 0;
//    while (i != father[i]) {
//        stack[idx++] = i;
//        i = father[i];
//    }
//    // ·��ѹ��
//    while (idx > 0) {
//        father[stack[--idx]] = i;
//    }
//    return i;
//}
//
//bool isSameSet(int x, int y) {
//    return find(x) == find(y);
//}
//
//void unionSets(int x, int y) {
//    int rootX = find(x);
//    int rootY = find(y);
//
//    if (rootX != rootY) {
//        if (size[rootX] >= size[rootY]) {
//            size[rootX] += size[rootY];
//            father[rootY] = rootX;
//        }
//        else {
//            size[rootY] += size[rootX];
//            father[rootX] = rootY;
//        }
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    while (cin >> n >> m) {
//        build(n);
//        for (int i = 0; i < m; i++) {
//            int op, x, y;
//            cin >> op >> x >> y;
//            if (op == 1) {
//                // ��ѯ�Ƿ�����ͬһ����
//                cout << (isSameSet(x, y) ? "Yes" : "No") << "\n";
//            }
//            else {
//                // �ϲ�����
//                unionSets(x, y);
//            }
//        }
//    }
//
//    return 0;
//}
