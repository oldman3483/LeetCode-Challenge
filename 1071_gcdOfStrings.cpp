#include <iostream>
#include <cstring>

class Solution
{
public:
    std::string gcdOfStrings(std::string str1, std::string str2)
    {

        int len1 = str1.length();
        int len2 = str2.length();

        if (str1 + str2 != str2 + str1)
        {
            return ""; // 如果两个字符串无法通过拼接得到相同的字符串，直接返回空字符串
        }

        // 使用輾轉相除法找到最大公共前缀长度
        while (len2 != 0)
        {
            int temp = len2;
            len2 = len1 % len2;
            len1 = temp;
        }

        return str1.substr(0, len1); // 返回最大公共前缀
    }
};

int main()
{
    std::string str1 = "LEET";
    std::string str2 = "CODE";

    Solution soln;

    std::string result = soln.gcdOfStrings(str1, str2);

    std::cout << "Largest common divisor: " << result << std::endl;

    return 0;
}
