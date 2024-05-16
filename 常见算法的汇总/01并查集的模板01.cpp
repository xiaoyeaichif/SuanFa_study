#include <iostream>
#include <vector>
using namespace std;

static const int MAXN = 1000001;

static int father[MAXN];
static int Size[MAXN];   //辅助矩阵，用来记录集合的大小
static int stack[MAXN]; // 辅助栈，用于路径压缩

static void build(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        Size[i] = 1; //初始化时,集合的大小都为1
    }
}

//优化递归的版本,这样可以防止栈溢出
static int find(int i) {
    int idx = 0;
    while (i != father[i]) {
        stack[idx++] = i;
        i = father[i];
    }
    // 路径压缩
    while (idx > 0) {
        father[stack[--idx]] = i;
    }
    return i;
}

static bool isSameSet(int x, int y) {
    return find(x) == find(y);
}

//这里采用的优化是,一定是小的个数的集合挂在大的个数集合的上面
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
                unionSets(x, y); // 合并集合
            }
            else { //z = 2代表比较操作
                // 查询是否属于同一集合
                cout << (isSameSet(x, y) ? "Y" : "N") << "\n";
            }
        }
    }

    return 0;
}
