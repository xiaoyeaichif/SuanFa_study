#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
#include<string>

using namespace std;

static const int N = 1010;
int g[N][N];
static int n, m;

/*
    假设输入的格式为:
    3 3
    1,2,3
    4,5,6
    7,8,9
*/




//处理字符间以逗号分割的类型
//指定输入的数组的大小
int main_input01() {
    cin >> n >> m;
    /*
        scanf("%d,"&w[i])  //以,为分隔符
        scanf("%d?",&w[i]);  //以?为分隔符
    */


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 使用逗号作为分隔符读取数字
            if (j < m - 1) {
                scanf("%d,", &g[i][j]);  // 读取数字并跳过逗号
            }
            else {
                scanf("%d", &g[i][j]);   // 读取最后一个数字（无逗号）
            }

        }
        /*
            puts("Hello");  // 输出 "Hello" 并换行
            puts("");       // 输出一个空行（换行）
            puts("World");  // 输出 "World" 并换行

        */
        //可以不适用这个puts函数
        //puts("");
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

/*
    scanf常见的输入格式如下：
    1：读取整数（int）：
        %d: 读取一个十进制整数。
        %i: 读取一个整数，可以根据输入的前缀确定进制（如0x表示十六进制）。
        %ld, %li: 读取一个长整数。
        %u: 读取一个无符号整数。

    2：读取浮点数（float 或 double）：
        %f: 读取一个浮点数。
        %lf: 读取一个双精度浮点数。
        
    3：读取字符（char）：
        %c: 读取一个字符。

    4：读取字符串（char[] 或 char*）：
        %s: 读取一个字符串，遇到空格、制表符或换行符时停止读取。

*/