#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main_input05(){
    string line;
    getline(cin, line);  // 读取一行输入

    istringstream iss(line);
    vector<int> nums;
    int num;

    // 将输入的数字逐个读取并存储到 vector<int> nums 中
    //会自动跳过空格
    while (iss >> num) {
        nums.push_back(num);
    }

    // 对 nums 中的数字进行排序
    sort(nums.begin(), nums.end());

    // 输出排序后的结果
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ' ';  // 输出数字间的空格，最后一个数字后面不加空格
        }
    }
    cout << endl;

    return 0;
}
