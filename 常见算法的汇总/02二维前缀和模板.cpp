#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//全局变量使用
const int N = 10;
int n, m, q;
int a[N][N], s[N][N];

/*
1<= n <=1000
1<= q <=2*10^5
1<=x1 <= x2 <= n
1<=y1 <= y2 <= m
*/
int main02()
{
    cin >> n >> m >> q;
    //为什么从1开始是因为数据范围的问题
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
        }
    }
    //测试前缀和数组
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
        {
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }



    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}