#include <iostream>
using namespace std;


void replaceBlank(char string[], int length) { // length 为字符数组的总长度
    if (string == NULL or length <= 0) return;
    int length_pre = 0; // 原始长度
    int length_now = 0; // 替换后长度
    int number_blank = 0; // 空格数
    int i = 0;
    while (string[i] != '\0') {
        ++length_pre;
        if (string[i] == ' ')
            ++number_blank;
        ++i;
    }
    length_now = length_pre + number_blank * 2;
    if (length_now > length) return; // 字符数组不够用
    // 从字符串'\0'开始复制
    int index_pre = length_pre;
    int index_now = length_now; // 指定两个指针
    while(index_now>index_pre) {
        if (string[index_pre] == ' ') {
            string[index_now--] = '0';
            string[index_now--] = '2';
            string[index_now--] = '%';
        } else {
            string[index_now--] = string[index_pre];
        }
        --index_pre;
    }
    cout << string << endl;
}

int main() {
    char string[100] = "I love you lee.";
    replaceBlank(string, 100);
}