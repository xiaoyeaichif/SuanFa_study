#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input;
    cin >> input;  // 读取整个输入

    // 去除方括号
    // 长度减去2
    input = input.substr(1, input.size() - 2);

    // 使用 stringstream 解析
    istringstream iss(input);
    vector<int> numbers;
    string number;
    while (getline(iss, number, ',')) {
        numbers.push_back(stoi(number));  // 将字符串转换为整数并存储到 vector 中
    }

    // 输出结果验证
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
