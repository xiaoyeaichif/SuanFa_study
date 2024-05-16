#include <iostream>
#include <sstream>
#include <string>
using namespace std;

static const int N = 1010;
static int g[N][N];

int main_input04() {
    int n, m;
    cin >> n >> m;  // 输入 n 和 m，表示二维数组的行数和列数

    //由于cin会把换行符留在输入流中,所以要使用下面的方法忽略他
    cin.ignore(); // 忽略换行符，准备读取下一行数据

    // 处理输入数据
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);  // 读取一行数据

        stringstream ss(input);  // 使用字符串流处理当前行数据
        string token;
        int j = 0;
        /*
        *   在流ss中获取以逗号分割的字符
        */
        while (getline(ss, token, ',')) {
            if (j < m) {
                // 将解析出的数字存储到二维数组中
                g[i][j] = stoi(token);  // 将字符串转成整数并存储
                j++;
            }
        }
    }

    // 输出二维数组
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
