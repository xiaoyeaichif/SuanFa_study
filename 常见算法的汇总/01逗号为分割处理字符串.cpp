#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
#include<string>

using namespace std;

static const int N = 1010;
int g[N][N];
static int n, m;

//�����ַ����Զ��ŷָ������
int main_douhao_01() {
    cin >> n >> m;
    /*
        scanf("%d,"&w[i])  //��,Ϊ�ָ���
        scanf("%d?",&w[i]);  //��?Ϊ�ָ���
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d,", &g[i][j]);
        }
        /*
            puts("Hello");  // ��� "Hello" ������
            puts("");       // ���һ�����У����У�
            puts("World");  // ��� "World" ������

        */
        puts("");
    }

    //�����ά����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}