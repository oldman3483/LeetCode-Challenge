#include <stdio.h>
#include <stdlib.h>
# define LEN 0xffff
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void recv(int *arr, int len, int index, int **ret, int* ret_index)
{
    int i;
    if(index==len-1)
    {
        ret[*ret_index] = (int*)malloc(sizeof(int)*len);
        memcpy(ret[*ret_index], arr, len * sizeof(int));
        (*ret_index)++;
        return;
    }
    for (i=index; i<len; i++)
    {
        swap(&arr[i], &arr[index]);
        printf("ret = %d\n", ret[i]);
        recv(arr, len, index+1, ret, ret_index);
        swap(&arr[i], &arr[index]);
    }
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** ans = (int**)malloc(sizeof(int*)*LEN);
    int* retSize = (int*)malloc(sizeof(int)*LEN);
    int retIndex =0;
    int i =0;

    recv(nums, numsSize, 0, ans, &retIndex);
    *returnColumnSizes=retSize;
    for(i=0; i<retIndex; i++)
    {
        retSize[i] = numsSize;
    }
    *returnSize = retIndex;
    return ans;
}

int main(void)
{
    return 0;
}
