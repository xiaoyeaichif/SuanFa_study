#include <iostream>
#include <sstream>
#include <string>
using namespace std;

static const int N = 1010;
static int g[N][N];

int main_input04() {
    int n, m;
    cin >> n >> m;  // ���� n �� m����ʾ��ά���������������

    //����cin��ѻ��з�������������,����Ҫʹ������ķ���������
    cin.ignore(); // ���Ի��з���׼����ȡ��һ������

    // ������������
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);  // ��ȡһ������

        stringstream ss(input);  // ʹ���ַ���������ǰ������
        string token;
        int j = 0;
        /*
        *   ����ss�л�ȡ�Զ��ŷָ���ַ�
        */
        while (getline(ss, token, ',')) {
            if (j < m) {
                // �������������ִ洢����ά������
                g[i][j] = stoi(token);  // ���ַ���ת���������洢
                j++;
            }
        }
    }

    // �����ά����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
