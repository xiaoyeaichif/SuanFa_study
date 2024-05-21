#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;




int main_input06() {
    //获取以逗号分割的字符串
    /*
    *  比如 str = "yejie,nihao,nizaina"
    *  最终要输出的是yejie nihao nizaina
    */
    string str;
    getline(cin, str);

    //接下来将使用字符串流处理当前行数据
    istringstream ss(str);//或者使用    stringstream ss(str)也是可以的
    vector<string>ans;
    //将分割的字符串存在数组中
    string token;
    while (getline(ss, token, ','))
    {
        ans.push_back(token);// 将每个逗号分隔的字段存储到 vector 中
    }

    //输出字符串
    for (string s : ans)
    {
        cout << s << ' ';
    }
    cout << endl;
    
    return 0;
}

