#include <iostream>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int count = 0;
        int size = flowerbed.size();
        int i = 0;

        while (i < size)
        {
            if (flowerbed[i] == 0)
            {
                // 当前位置为空地
                if (i == 0 || flowerbed[i - 1] == 0)
                {
                    // 前一个位置为空地或当前位置是第一个位置
                    if (i == size - 1 || flowerbed[i + 1] == 0)
                    {
                        // 后一个位置为空地或当前位置是最后一个位置
                        flowerbed[i] = 1; // 在当前位置种花
                        count++;
                    }
                }
            }
            i++;
        }
        return count >= n;
    }
};

int main()
{
    // vector<int> flowerbed({0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0});
    vector<int> flowerbed = {0, 0, 1};

    int n = 17; // 你可以改变 n 的值来测试不同的情况

    Solution soln;

    bool result = soln.canPlaceFlowers(flowerbed, n);
    if (result)
    {
        std::cout << "可以种植 " << n << " 朵新花。" << std::endl;
    }
    else
    {
        std::cout << "无法种植 " << n << " 朵新花。" << std::endl;
    }

    return 0;
}
