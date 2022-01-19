#include <stdio.h>
#include <stdlib.h>


int lengthOfLongestSubstring(char * s){
    char *r_ptr;
    char *l_ptr;
    int cnt=0;
    int max=0;
    r_ptr = s;
    l_ptr = s;
    /*
    for(int i=0;i<strlen(s);i++)
    {

        for(int j=0;j<i;j++)
        {

        }
        
    }
    */
   
   printf("%d", s);
   printf("\n");
   printf("%s", r_ptr+1);
   return 0;
}

int main(void)
{

    char *s = "abcabcbb";
    printf("%s", s);
    lengthOfLongestSubstring(s);
}