#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static inline void __swap(int* nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void nextPermutation(int* nums, int numsSize){
    if (numsSize <= 1) {
        return;
    }
    if (numsSize == 2) {
        __swap(nums, 0, 1);
        return;
    }
    int first_decend = -1;

    // find first number of descending part from the right
    /*
    for (int i=numsSize-1; i>0; i--)
    {
        if(nums[i-1]<nums[i] || i-1==0)
        {
            first_decend = i-1;
            break;
        }
    }
    */
    for (int j = numsSize - 1, i = j - 1; j >= 0; j--, i--) {
        if (i < 0 || nums[i] < nums[j]) {
            first_decend = j-1;
            break;
        }
    }
    // if there is a number before descending part, swap it with just larger
    // number in descending part to get next larger number of permutation
    if (first_decend>0)
    {
        int higher = first_decend;
        for(int j=first_decend+1; j<numsSize; j++)
        {
            if(nums[first_decend]<nums[j])
            {
                higher = j;
            }
        }
        __swap(nums, first_decend, higher);
    }

    // no matter we increase number before descending part or not, we need to
    // reverse descending part to get the next permutation
    int start = first_decend+1;
    int end   = numsSize - 1;
    while(start < end)
    {
        __swap(nums, start++, end--);
    }
}

static inline void
__swap(int *a, int v, int m)
{       
    int x = a[m];
    a[m] = a[v];
    a[v] = x;
}

void
nextPermutation(int *nums, int numsSize)
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
    }

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
    
    return 0;
}