#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lengthOfLongestSubstring(char * s){
    int *string_index = malloc(sizeof(int)*1024);
    int start_index=0;
    int max = 0;
    for (int i=0; i<1024; i++)
        string_index[i] = -1;
    
    for(int i=0;i<strlen(s);i++)
    {
        if (string_index[s[i]] >= start_index)
        {
            start_index = string_index[s[i]]+1;
            string_index[s[i]] = i; 

            printf("start i = %d", start_index);
            printf("\n");
        }
        else
        {
            string_index[s[i]] = i;
                if (i-start_index+1>max)
                    max = string_index[s[i]] - start_index +1;
        }
        printf("\ni = %d", i);
        printf("\n");
        
    }
   return max;
}

int main(void)
{
    int out;
    char *s = "abcabcbb";
    char *s2 = "aab";
    printf("%s", s);
    out = lengthOfLongestSubstring(s2);
    printf("\n%d", out);
}