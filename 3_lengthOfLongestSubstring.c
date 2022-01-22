#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lengthOfLongestSubstring(char * s){
    int *string_index = malloc(sizeof(int)*1024);
    int start_index=0;
    int max = 0;
    int cnt = 0;

    for (int i=0; i<1024; i++)
        string_index[i] = -1;
    
    for(int i=0;i<strlen(s);i++)
    {
        if (string_index[s[i]] > start_index)
        {
            if (cnt>max)
                max = string_index[s[i]] - start_index+1;
            start_index = string_index[s[i]];
            cnt = 0;
        }
        else
            string_index[s[i]] = i;
        cnt++;
    }
   return max;
}

int main(void)
{
    int out;
    char *s = "abcabcbb";
    printf("%s", s);
    out = lengthOfLongestSubstring(s);
    printf("\n%d", out);
}