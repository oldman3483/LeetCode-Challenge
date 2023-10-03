#include <iostream>
#include <cstring>


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int len1 = word1.length();
        int len2 = word2.length();
        int count = len1 + len2;
        string result = "";

        int i, j =0;

        while(i < len1 && j < len2)
        {
            result += word1[i++];
            result += word2[j++];
        }

        while (i < len1)
        {
            result += word1[i++];
        }
        
        while (j<len2)
        {
            result += word2[j++];
        }
        
        return result;
    }
};