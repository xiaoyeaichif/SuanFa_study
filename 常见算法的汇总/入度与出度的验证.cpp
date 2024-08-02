

// 核心就是统计树的入度和出度即可


//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main_yanz05()
{
    int n;
    cin >> n;
    // 入度矩阵和出度矩阵的创建
    vector<int>Input_(n + 1, 0);
    vector<int>Output_(n + 1, 0);
    for(int i = 1;i < n;i++)
    {
        int a, b;
        cin >> a >> b;
        //出度
        Output_[a]++;
        //入度
        Input_[b]++;

    }
    // 遍历出度和入度即可
    int ans = 0;
    /*for (int i = 1; i <= n; i++)
    {
        if (Input_[i] == 1 && Output_[i] == 1)
        {
            ans++;
        }
    }*/
    for (int i = 0; i <= n; i++)
    {
        cout << Input_[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << Output_[i] << ' ';
    }
    //cout << ans << endl;
    return 0;
}