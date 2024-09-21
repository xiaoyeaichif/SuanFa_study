


// 要做的就是提取每个单词的长度

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

int main_str01()
{
    string str;
    getline(cin, str);
    // 将句子按空格分割
    istringstream iss(str);
    string line;
    vector<string>ans;
    // 以空格拆分字符串
    while (getline(iss, line, ' '))
    {
        ans.push_back(line);
        // 
        cout << line << ' ';
    }
    int size = ans.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ans[i].size();
    }
    // printf("%.2f\n", static_cast<double>(sum) / size);
    cout << fixed << setprecision(2) << static_cast<double>(sum) / size << endl;
    return 0;
}