//#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;


const int N = 1010;
vector<vector<int>>yuan_s(N, vector<int>(N, 0));
vector<vector<int>>Presum(N, vector<int>(N, 0));

//Ҫ��ȡ����ĵ����Ͻ��±�

int main_erwei03()
{
    int n, m, C;
    cin >> n >> m >> C;
    //����ά�����Լ�ǰ׺������
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> yuan_s[i][j];
            Presum[i][j] = yuan_s[i][j] +
                Presum[i][j - 1] +
                Presum[i - 1][j] -
                Presum[i - 1][j - 1];
        }
    }
    //������������CxC�����ֵ
    /*
        �������Ͻǵĵ�λ�ã�����������ֵ����
    */
    int ans = INT_MIN;
    int x = -1, y = -1;
    for (int i = 1; i <= n - C + 1; i++)
    {
        for (int j = 1; j <= m - C + 1; j++)
        {
            //�����½ǵ�Ԫ��
            int x1 = i + C - 1, y1 = j + C - 1;
            int res = Presum[x1][y1] - Presum[x1][j - 1] -
                Presum[i - 1][y1] + Presum[i - 1][j - 1];
            if (res > ans)
            {
                x = i;
                y = j;
                ans = res;
            }

        }
    }
    cout << x << " " << y << endl;
    return 0;
}