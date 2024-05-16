#include <iostream>
#include <vector>
using namespace std;

static const int MAXN = 1000001;

static int father[MAXN];
static int Size[MAXN];   //��������������¼���ϵĴ�С
static int stack[MAXN]; // ����ջ������·��ѹ��

static void build(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        Size[i] = 1; //��ʼ��ʱ,���ϵĴ�С��Ϊ1
    }
}

//�Ż��ݹ�İ汾,�������Է�ֹջ���
static int find(int i) {
    int idx = 0;
    while (i != father[i]) {
        stack[idx++] = i;
        i = father[i];
    }
    // ·��ѹ��
    while (idx > 0) {
        father[stack[--idx]] = i;
    }
    return i;
}

static bool isSameSet(int x, int y) {
    return find(x) == find(y);
}

//������õ��Ż���,һ����С�ĸ����ļ��Ϲ��ڴ�ĸ������ϵ�����
static void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (Size[rootX] >= Size[rootY]) {
            Size[rootX] += Size[rootY];
            father[rootY] = rootX;
        }
        else {
            Size[rootY] += Size[rootX];
            father[rootX] = rootY;
        }
    }
}

int main_bincha01() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        build(n);
        for (int i = 0; i < m; i++) {
            int z, x, y;
            cin >> z >> x >> y;
            if (z == 1) {
                unionSets(x, y); // �ϲ�����
            }
            else { //z = 2����Ƚϲ���
                // ��ѯ�Ƿ�����ͬһ����
                cout << (isSameSet(x, y) ? "Y" : "N") << "\n";
            }
        }
    }

    return 0;
}
