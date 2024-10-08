#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100001;

int father[MAXN]; // ���鼯���飬�洢���ڵ�
int Size[MAXN];//���漯���еĸ���

// ��ʼ�����鼯����ÿ���ڵ�ĸ��ڵ��ʼ��Ϊ����
void build(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        Size[i] = 1;
    }
}

//�ݹ�汾���ҵ����ڵ�,���ǵݹ���ȹ����ջ���
//�汾1���Ż�����������
// ���ҽڵ��������ϵĸ��ڵ㣬ͬʱ����·��ѹ��
int find(int i) {
    if (father[i] != i) {
        father[i] = find(father[i]); // ·��ѹ�������ڵ�ֱ�����ӵ����ڵ�
    }
    return father[i]; // ���ؽڵ��������ϵĸ��ڵ�
}

// �ж������ڵ��Ƿ�����ͬһ������
bool isSameSet(int x, int y) {
    return find(x) == find(y); // �ж������ڵ�ĸ��ڵ��Ƿ���ͬ 
}

//�ϲ���������
//�������Ż�Ϊ���С,�汾1���漰��,�汾��û�漰
//************************************
// �ϲ��������ϣ���һ�����ϵĸ��ڵ����ӵ���һ�����ϵĸ��ڵ���
void unionSets(int x, int y) {
    int rootX = find(x); // ���� x �ڵ��������ϵĸ��ڵ�
    int rootY = find(y); // ���� y �ڵ��������ϵĸ��ڵ�

    if (rootX != rootY) {
        Size[rootY] += Size[rootX];//��x���ڼ��ϵ�Ԫ������ȫ���ӵ�y���ڵļ�����
        father[rootX] = rootY; // �� x ���ڼ��ϵĸ��ڵ����ӵ� y ���ڼ��ϵĸ��ڵ�
    }
}

int main_binchaji02() {
    //��ջ���
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
            else {
                // ��ѯ�Ƿ�����ͬһ����
                cout << (isSameSet(x, y) ? "Y" : "N") << "\n";
            }
        }
    }

    return 0;
}
