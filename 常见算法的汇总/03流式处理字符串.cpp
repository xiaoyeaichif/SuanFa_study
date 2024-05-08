#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> splitString(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;  // ���ڴ�ŷָ������ַ���
    std::string token;  // ���ÿ���ָ�������ַ���
    std::istringstream tokenStream(s);  // ʹ���ַ��������������ַ��� s תΪ��

    // ͨ��ѭ�������ж�ȡÿ�����ַ��������� delimiter ���зָҲ����getline�ĵ���������
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);  // ���ָ������ַ����������� tokens ��
    }

    return tokens;  // ���ش�ŷָ�����ַ���������
}


//int main() 
//{
//
//    std::cout << "Enter a string to split (using commas): ";
//    std::string str;
//    //���ָ���ַ�
//    char delimiter = ',';
//    while (std::getline(std::cin, str)) { // �ӱ�׼�����ȡһ���ַ���
//
//
//        // ���÷ָ�������ָ��Ľ������ result ����
//        std::vector<std::string> result = splitString(str, delimiter);
//
//        //���ÿ���ַ����ͻ���,
//        for (const auto& token : result) {
//            std::cout << token << ' ';
//        }
//        std::cout << std::endl;
//        //ͳ������ĳ���,�����б���Ķ����ַ���
//        std::cout << result.size() << std::endl;
//
//    }
//    return 0;
//}


int main_zifuc() {
    std::cout << "Enter rows of comma-separated elements (press Enter twice to finish):\n";

    std::vector<std::vector<int>> matrix;  // ��ά���飬���ڴ洢�������Ԫ��
    std::string line;
    char delimiter = ',';  // ָ���ָ���Ϊ����

    // ѭ����ȡ�����ÿһ������
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;  // ����������У���������ѭ��
        }

        // �ָǰ���ַ������õ�����Ԫ�ص��ַ�����ʽ
        std::vector<std::string> elements = splitString(line, delimiter);

        // ���ַ�����ʽ��Ԫ��ת��Ϊ������������һά����
        std::vector<int> row;
        for (const std::string& elem : elements) {
            int num = std::stoi(elem);  // ���ַ���ת��Ϊ����
            row.push_back(num);  // ����������һά����
        }

        // ����ǰ�н������һά��������ά����
        matrix.push_back(row);
    }

    // ���������Ķ�ά����
    std::cout << "Parsed 2D matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
