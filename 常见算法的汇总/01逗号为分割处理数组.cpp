#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
#include<string>

using namespace std;

static const int N = 1010;
int g[N][N];
static int n, m;

/*
    ��������ĸ�ʽΪ:
    3 3
    1,2,3
    4,5,6
    7,8,9
*/




//�����ַ����Զ��ŷָ������
//ָ�����������Ĵ�С
int main_input01() {
    cin >> n >> m;
    /*
        scanf("%d,"&w[i])  //��,Ϊ�ָ���
        scanf("%d?",&w[i]);  //��?Ϊ�ָ���
    */


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // ʹ�ö�����Ϊ�ָ�����ȡ����
            if (j < m - 1) {
                scanf("%d,", &g[i][j]);  // ��ȡ���ֲ���������
            }
            else {
                scanf("%d", &g[i][j]);   // ��ȡ���һ�����֣��޶��ţ�
            }

        }
        /*
            puts("Hello");  // ��� "Hello" ������
            puts("");       // ���һ�����У����У�
            puts("World");  // ��� "World" ������

        */
        //���Բ��������puts����
        //puts("");
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

/*
    scanf�����������ʽ���£�
    1����ȡ������int����
        %d: ��ȡһ��ʮ����������
        %i: ��ȡһ�����������Ը��������ǰ׺ȷ�����ƣ���0x��ʾʮ�����ƣ���
        %ld, %li: ��ȡһ����������
        %u: ��ȡһ���޷���������

    2����ȡ��������float �� double����
        %f: ��ȡһ����������
        %lf: ��ȡһ��˫���ȸ�������
        
    3����ȡ�ַ���char����
        %c: ��ȡһ���ַ���

    4����ȡ�ַ�����char[] �� char*����
        %s: ��ȡһ���ַ����������ո��Ʊ�����з�ʱֹͣ��ȡ��

*/