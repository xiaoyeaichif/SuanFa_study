#include <iostream>
#include <sstream>
#include <string>
using namespace std;

static const int N = 1010;
static int g[N][N];

int main_input04() {
    //输入矩阵的长和宽
    int n, m;
    cin >> m >> n;
    //要注意使用cin会把空格留在输入中,所以要忽略它
    cin.ignore();
    //接下来在流中处理数组中的元素
    for (int i = 0; i < m; i++) //循环获取每一行
    {
        string line;
        //获取一行数据
        getline(cin, line);
        // 使用字符串流处理当前行数据
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
