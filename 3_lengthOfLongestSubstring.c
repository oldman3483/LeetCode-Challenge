#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lengthOfLongestSubstring(char * s){
    char *r_ptr;
    char *l_ptr;
    int cnt=0;
    int max=0;
    int stone=0;
    r_ptr = s;
    l_ptr = s;
    
    for(int i=0;i<strlen(s);i++)
    {
        l_ptr = s + stone;
        for(int j=0;j<i;j++)
        {
            if (*r_ptr == *l_ptr)
                stone = j;
                cnt = 0;
                r_ptr = l_ptr;
            l_ptr++;
        }
        if (cnt>max)
            max = cnt;
        r_ptr++;
        cnt++;
        max++;
    }
    
    
   
   printf("\n%d", s);
   printf("\n");
   printf("%d", r_ptr+1);
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