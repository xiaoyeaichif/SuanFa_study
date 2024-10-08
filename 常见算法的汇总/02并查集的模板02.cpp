#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100001;

int father[MAXN]; // 并查集数组，存储父节点
int Size[MAXN];//保存集合中的个数

// 初始化并查集，将每个节点的父节点初始化为自身
void build(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        Size[i] = 1;
    }
}

//递归版本的找到根节点,但是递归深度过深会栈溢出
//版本1中优化了这种现象
// 查找节点所属集合的根节点，同时进行路径压缩
int find(int i) {
    if (father[i] != i) {
        father[i] = find(father[i]); // 路径压缩，将节点直接连接到根节点
    }
    return father[i]; // 返回节点所属集合的根节点
}

// 判断两个节点是否属于同一个集合
bool isSameSet(int x, int y) {
    return find(x) == find(y); // 判断两个节点的根节点是否相同 
}

//合并两个集合
//还可以优化为大挂小,版本1中涉及了,版本二没涉及
//************************************
// 合并两个集合，将一个集合的根节点连接到另一个集合的根节点上
void unionSets(int x, int y) {
    int rootX = find(x); // 查找 x 节点所属集合的根节点
    int rootY = find(y); // 查找 y 节点所属集合的根节点

    if (rootX != rootY) {
        Size[rootY] += Size[rootX];//将x所在集合的元素数量全部加到y所在的集合中
        father[rootX] = rootY; // 将 x 所在集合的根节点连接到 y 所在集合的根节点
    }
}

int main_binchaji02() {
    //清空缓存
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
            else {
                // 查询是否属于同一集合
                cout << (isSameSet(x, y) ? "Y" : "N") << "\n";
            }
        }
    }

    return 0;
}
