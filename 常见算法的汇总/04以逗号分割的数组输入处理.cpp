#include <iostream>
#include <sstream>
#include <string>
using namespace std;

static const int N = 1010;
static int g[N][N];

int main_input04() {
    //�������ĳ��Ϳ�
    int n, m;
    cin >> m >> n;
    //Ҫע��ʹ��cin��ѿո�����������,����Ҫ������
    cin.ignore();
    //�����������д��������е�Ԫ��
    for (int i = 0; i < m; i++) //ѭ����ȡÿһ��
    {
        string line;
        //��ȡһ������
        getline(cin, line);
        // ʹ���ַ���������ǰ������
        stringstream ss(line);
        int j = 0;
        string str;
        while (getline(ss, str, ','))
        {
            if (j < n)
            {
                 g[i][j] = stoi(str);
                 j++;
            }
           
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
