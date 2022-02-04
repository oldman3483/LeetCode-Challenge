#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b)                                                                                                                                                                       
{
    if(!a || !b)
       return;
    char temp = *(a);
    *(a) = *(b);
    *(b) = temp;
}

void reverseString(char* s, int sSize){
    
    char* reverse = s;
    //*reverse = *s;
    int mid = sSize/2;
    printf("%d\n", mid);
    int i = 0;
    while((sSize/2-i)!=0)
    {
        if (sSize%2 == 1)
            swap(s+mid+i, s+mid-i);
        else
            swap(s+mid+i, s+mid-i-1);
        i++;
        printf("%d\n", i);
    }
    if (sSize%2 == 1)
        swap(s+mid+i, s+mid-i);

}

//another way
void reverseStringII(char* s, int sSize){
    int l = 0;
    int r = sSize-1;
    while(l<r)
    {
        swap(s+l, s+r);
        l++;
        r--;
    }
}

int main(void)
{
    char s[6] = {'h','e','l','l','o','\0'};
    char s2[5] = {'a', 'b', 'c', 'd', '\0'};
    reverseStringII(s, 5);
    printf("%s", s);
    return 0;
}