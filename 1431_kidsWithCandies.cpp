#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int nums = candies.size();
        vector<bool> output(nums, 0);
        int max = 0;

        for (int i = 0; i < nums; i++)
        {
            if (candies[i] > max)
            {
                max = candies[i];
            }
        }
        for (int i = 0; i < nums; i++)
        {
            if (candies[i] + extraCandies >= max)
            {
                output[i] = true;
            }
            else
            {
                output[i] = false;
            }
        }

        return output;
    }
};

#include <vector>

std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies)
{
    int maxCandies = *std::max_element(candies.begin(), candies.end()); // 找到最大的糖果数

    std::vector<bool> result;
    for (int candy : candies)
    {
        result.push_back(candy + extraCandies >= maxCandies);
    }

    return result;
}

int main()
{
    std::vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    std::vector<bool> result = kidsWithCandies(candies, extraCandies);

    for (bool canHaveMostCandies : result)
    {
        if (canHaveMostCandies)
        {
            std::cout << "true ";
        }
        else
        {
            std::cout << "false ";
        }
    }

    return 0;
}
