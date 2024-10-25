#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include <csignal>
#include <cstdint>

#include<memory>




using u_short = unsigned short;

// 将16进制数据转换为字节流
vector<uint8_t> hexTobyte(const string& str1) {
    vector<uint8_t> bytes;
    for (size_t i = 0; i < str1.size(); i += 2) {
        // 每次取两个字符
        string temp = str1.substr(i, 2);
        // 将字符转换为字节，并指定基数为16
        uint8_t byte = static_cast<uint8_t>(stoi(temp, nullptr, 16));
        bytes.push_back(byte);
    }
    return bytes;
}

// 从字节流中读取两个字节，按小端模式解析为 u_short
u_short readtwo(const vector<uint8_t>& data, size_t offset) {
    // 小端处理，将高位移动到高8位上
    return data[offset] | (data[offset + 1] << 8);
    // 大端处理
    // return (data[offset] << 8) | data[offset + 1];

}

// 解析字节流并输出协议内容
void getsolve(const vector<uint8_t>& data) {
    size_t i = 0;
    while (i + 4 <= data.size()) {  // 确保剩余至少4字节用于读取常量和长度字段
        // 检查常量是否为 'SS'
        if (data[i] != 'S' || data[i + 1] != 'S') {
            i++;  // 如果常量不匹配，移动到下一个字节继续检查
            continue;
        }

        // 读取消息长度
        u_short len = readtwo(data, i + 2);

        // 检查整个协议包是否完整
        if (i + 4 + len > data.size()) {
            break;  // 数据不完整，等待下次读取
        }

        // 读取协议号
        u_short proto = readtwo(data, i + 4);

        // 计算消息体的长度（减去协议号的2个字节）
        size_t message_length = len - 2;

        // 读取消息体
        string message(data.begin() + i + 6, data.begin() + i + 6 + message_length);

        // 输出协议号和消息体
        cout << proto << ' ' << message << endl;

        // 移动索引，准备解析下一个协议
        i += 4 + len;  // 4字节（常量和长度字段）加上len（协议号和消息体）
    }
}

int main_shenxinfu() {
    string str1;
    getline(cin, str1);  // 从标准输入读取16进制字符串
    auto temp = hexTobyte(str1);  // 将16进制字符串转换为字节流
    getsolve(temp);  // 解析并输出协议内容
    return 0;
}
