#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> splitString(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;  // 用于存放分割后的子字符串
    std::string token;  // 存放每个分割出的子字符串
    std::istringstream tokenStream(s);  // 使用字符串流，将输入字符串 s 转为流

    // 通过循环从流中读取每个子字符串，按照 delimiter 进行分割，也就是getline的第三个参数
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);  // 将分割后的子字符串存入向量 tokens 中
    }

    return tokens;  // 返回存放分割后子字符串的向量
}


//int main() 
//{
//
//    std::cout << "Enter a string to split (using commas): ";
//    std::string str;
//    //待分割的字符
//    char delimiter = ',';
//    while (std::getline(std::cin, str)) { // 从标准输入读取一行字符串
//
//
//        // 调用分割函数，将分割后的结果存入 result 向量
//        std::vector<std::string> result = splitString(str, delimiter);
//
//        //输出每个字符串就换行,
//        for (const auto& token : result) {
//            std::cout << token << ' ';
//        }
//        std::cout << std::endl;
//        //统计数组的长度,数组中保存的都是字符串
//        std::cout << result.size() << std::endl;
//
//    }
//    return 0;
//}


int main_zifuc() {
    std::cout << "Enter rows of comma-separated elements (press Enter twice to finish):\n";

    std::vector<std::vector<int>> matrix;  // 二维数组，用于存储解析后的元素
    std::string line;
    char delimiter = ',';  // 指定分隔符为逗号

    // 循环读取输入的每一行数据
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;  // 如果遇到空行，结束输入循环
        }

        // 分割当前行字符串，得到各个元素的字符串形式
        std::vector<std::string> elements = splitString(line, delimiter);

        // 将字符串形式的元素转换为整数，并存入一维数组
        std::vector<int> row;
        for (const std::string& elem : elements) {
            int num = std::stoi(elem);  // 将字符串转换为整数
            row.push_back(num);  // 将整数存入一维数组
        }

        // 将当前行解析后的一维数组存入二维数组
        matrix.push_back(row);
    }

    // 输出解析后的二维数组
    std::cout << "Parsed 2D matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
