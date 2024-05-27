#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int kthLargestValue1(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>>Pre_XoR(m, vector<int>(n, 0));
    Pre_XoR[0][0] = matrix[0][0];
    //填写第一行
    for (int j = 1; j < n; j++)
    {
        Pre_XoR[0][j] = Pre_XoR[0][j - 1] ^ matrix[0][j];
    }
    //填写第一列
    for (int i = 1; i < m; i++)
    {
        Pre_XoR[i][0] = Pre_XoR[i - 1][0] ^ matrix[i][0];
    }
    //填写表格其他位置
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            Pre_XoR[i][j] = Pre_XoR[i - 1][j] ^
                Pre_XoR[i][j - 1] ^
                Pre_XoR[i - 1][j - 1] ^
                matrix[i][j];
        }
    }
   /* for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Pre_XoR[i][j] << " ";
        }
        cout << endl;
    }*/

    vector<int>ans;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans.push_back(Pre_XoR[i][j]);
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    return ans[k - 1];
}


//小根堆做法
int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>>Pre_XoR(m, vector<int>(n, 0));
    Pre_XoR[0][0] = matrix[0][0];
    //填写第一行
    for (int j = 1; j < n; j++)
    {
        Pre_XoR[0][j] = Pre_XoR[0][j - 1] ^ matrix[0][j];
    }
    //填写第一列
    for (int i = 1; i < m; i++)
    {
        Pre_XoR[i][0] = Pre_XoR[i - 1][0] ^ matrix[i][0];
    }
    //填写表格其他位置
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            Pre_XoR[i][j] = Pre_XoR[i - 1][j] ^
                Pre_XoR[i][j - 1] ^
                Pre_XoR[i - 1][j - 1] ^
                matrix[i][j];
        }
    }
    /* for (int i = 0; i < m; i++)
     {
         for (int j = 0; j < n; j++)
         {
             cout << Pre_XoR[i][j] << " ";
         }
         cout << endl;
     }*/

     //使用小根堆记录第k大的值
     priority_queue<int, vector<int>, greater<int>>p_que;
     for (int i = 0; i < m; i++)
     {
         for (int j = 0; j < n; j++)
         {
             int N = p_que.size();
             if (N < k)//小根堆中元素还没到达k个
             {
                 p_que.push(Pre_XoR[i][j]);
             }
             else {
                 if (p_que.top() < Pre_XoR[i][j])
                 {
                     p_que.pop();
                     p_que.push(Pre_XoR[i][j]);
                 }
             }
         }
     }
     return p_que.top();
   
}
int main_1738()
{
    vector<vector<int>>matrix = { {5, 2,3},{1, 6,4},{5,7,6} };
    int ans = kthLargestValue(matrix, 1);
    cout << ans << endl;
    return 0;
}