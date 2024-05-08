#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
#include<string>

using namespace std;

static const int N = 1010;
int g[N][N];
static int n, m;

//处理字符间以逗号分割的类型
int main_douhao_01() {
    cin >> n >> m;
    /*
        scanf("%d,"&w[i])  //以,为分隔符
        scanf("%d?",&w[i]);  //以?为分隔符
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d,", &g[i][j]);
        }
        /*
            puts("Hello");  // 输出 "Hello" 并换行
            puts("");       // 输出一个空行（换行）
            puts("World");  // 输出 "World" 并换行

        */
        puts("");
    }

    //输出二维矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}