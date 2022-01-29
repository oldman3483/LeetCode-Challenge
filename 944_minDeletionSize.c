#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int minDeletionSize(char ** strs, int strsSize){
    // *(*(A+行)+列)

    int j = 0;
    int del = 0;

    while (*(*(strs)+j) != 0 )
    {
        for (int i=1; i<strsSize; i++)
        {
            if(*(*(strs+i)+j) < *(*(strs+i-1)+j))
            {
                del++;
                break;
            }
        }
        j++;
    }
    return del;
}





int main(void)
{
    char *strs[] = {"cba","daf","ghi"};
    int out ;
    out = minDeletionSize(strs, 3);
    printf("%d\n", out);

    return 0;

}