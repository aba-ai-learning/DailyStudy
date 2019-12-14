/*
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;
class Solution
{
public:
    string replaceSpace(char *str, int length)
    {
        /*
            遍历str，当str[i] != ' ', new_string[count] = str[i], 反之相等
            string初始化 string str = " "; 内部operator+ 函数可以直接实现字符串的拼接
            char* 是原始类型的一个指针变量，指向一个内存地址，存储char型的数据
            string是一个类，是标准库的一部分
        */
       string new_string = "";
       for (int i = 0; i < length; i++)
       {
           if(str[i] == ' ')
           {
               new_string += "%20";
           }
           else
               new_string += str[i];
       }

       return new_string;
    }
    void replaceSpace2(char* str, int length)
    {
        /*
        调用函数后str指针所指向的字符串中的空格变为特定字符，length为指针指向的内存块长度
        */
        if(str == nullptr)
        {
            return;
        }
        int count_blank_num = 0;
        int orig_str_length = 0;
        int new_str_length = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if(str[i] == ' ')
            {
                count_blank_num ++;
                new_str_length += 3;
            }
            else
            {
                new_str_length += 1;
            }
            orig_str_length ++;
        }
        if (new_str_length > length)
            return;

        str[new_str_length--] = '\0';
        /*
        此处为i >= 0
        for 循环中先init部分在判断，若判断为真则循环主体，之后再进入第三部分的i--
        */
        for(int i = orig_str_length-1; i >= 0; i--) 
        {
            if(str[i] == ' ')
            {
                str[new_str_length--] = '0';
                str[new_str_length--] = '2';
                str[new_str_length--] = '%';
            }
            else{
                str[new_str_length--] = str[i];
            }
        }

    }
};

int main(int argc, char* argv[])
{
    Solution solution;
    char str[30] = "We are happy";
    solution.replaceSpace2(str, 30);
    cout << str << endl;
}