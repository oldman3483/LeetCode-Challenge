#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static inline void __swap(int *a, int v, int m)
{       
    int x = a[m];
    a[m] = a[v];
    a[v] = x;
}

void nextPermutation(int *nums, int numsSize)
{
    if (numsSize <= 1) {
        return;
    }
    if (numsSize == 2) {
        __swap(nums, 0, 1);
        return;
    }

    // find first number of descending part from the right
    int firstDesc = numsSize;
    for (int j = numsSize - 1, i = j - 1; j >= 0; j--, i--) {
        if (i < 0 || nums[i] < nums[j]) {
            firstDesc = j;
            break;
        }
    }
    

    // if there is a number before descending part, swap it with just larger
    // number in descending part to get next larger number of permutation
    if (firstDesc > 0) {
        int justHigherNum = firstDesc;
        for (int i = firstDesc; i < numsSize; i++) {
            if (nums[i] > nums[firstDesc - 1]) {
                justHigherNum = i;
            }
        }
        __swap(nums, firstDesc - 1, justHigherNum);
        printf("%d\n", justHigherNum);

    }
    printf("%d\n", firstDesc);




    // no matter we increase number before descending part or not, we need to
    // reverse descending part to get the next permutation
    int start = firstDesc;
    int end   = numsSize - 1;
    while (start < end) {
        __swap(nums, start++, end--);
    }
}


int main(void)
{
    int nums[3] = {3, 2, 1};
    nextPermutation(nums, 3);
    for(int i=0; i<3;i++)
    {
        printf("%d", *(nums+i));

    }
    
    return 0;
}