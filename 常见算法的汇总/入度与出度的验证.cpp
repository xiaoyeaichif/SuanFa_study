

// ���ľ���ͳ��������Ⱥͳ��ȼ���


//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main_yanz05()
{
    int n;
    cin >> n;
    // ��Ⱦ���ͳ��Ⱦ���Ĵ���
    vector<int>Input_(n + 1, 0);
    vector<int>Output_(n + 1, 0);
    for(int i = 1;i < n;i++)
    {
        int a, b;
        cin >> a >> b;
        //����
        Output_[a]++;
        //���
        Input_[b]++;

    }
    // �������Ⱥ���ȼ���
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