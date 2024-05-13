#include<iostream>
#include<vector>

using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // 创建二维前缀和数组，大小为(m+1) x (n+1)
    vector<vector<int>> Presum(m + 1, vector<int>(n + 1, 0));

    // 填充二维前缀和数组,遍历的是前缀和数组
    for (int i = 1; i < m+1; i++) {
        for (int j = 1; j < n+1; j++) {
            // 注意这里是 (i-1) 和 (j-1) 才对应到原始矩阵的位置
            Presum[i][j] = Presum[i - 1][j] + Presum[i][j - 1] - Presum[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }

    // 输出二维前缀和数组（调试用）
    /*for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << Presum[i][j] << ' ';
        }
        cout << endl;
    }*/

    //用来遍历正方形的大小
    int index = min(n, m);
    //记录满足的个数
    int ans = 0;
    while (index > 0)
    {
        for (int i = 1; i <= m - index + 1; i++)
        {
            for (int j = 1; j <= n - index + 1; j++)
            {
                //遍历能偶成正方形的的下标
                int x1 = i + index - 1;
                int y1 = j + index - 1;
                int sum = Presum[x1][y1] - Presum[x1][j - 1] -
                    Presum[i - 1][y1] + Presum[i - 1][j - 1];
                if (sum == index * index)
                {
                    ans += 1;
                }
            }
        }
        index -= 1;
    }
    return ans;
}
int main_qian_03()
{
    vector<vector<int>>matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    int ans = countSquares(matrix);
    cout << ans << endl;
    return 0;
}