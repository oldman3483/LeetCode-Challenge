#include <stdio.h>
#include <stdlib.h>

void __swap(int* nums, int n, int m)
{
    int tmp = nums[n];
    nums[n] = nums[m];
    nums[m] = tmp;
}

void nextPermute(int* nums, int numsSize)
{
    if (numsSize <= 1) {
        return;
    }
    if (numsSize == 2) {
        __swap(nums, 0, 1);
        return;
    }
    /* // one pointer will cause abort error waste to much time, out of the runtime
    for(int end=numsSize-1; end>0; end--)
    {
        if (nums[end]>nums[end-1])
        {
            des_first = end;
            break;
        }
    } 
    */
    // two pointer 
    int des_first = numsSize;
    for(int end=numsSize-1, end_next=end-1 ; end>=0; end--, end_next--)
    {
        if (end_next<0 || nums[end]>nums[end_next])
        {
            des_first = end;
            break;
        }
    }
    int higher = des_first;

    for(int i = des_first; i<numsSize; i++)
    {
        if(nums[i]>nums[des_first-1])
        {
            higher = i;
        }
    }
    __swap(nums, des_first-1, higher);
    
    int start = des_first;
    int end_des = numsSize-1;
    while(start < end_des)
    {
        __swap(nums, start, end_des);
        start++;
        end_des--;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    return 0;
}

int main(void)
{
    int nums[3] = {3, 2, 1};
    int size_nums = 3;
    nextPermute(nums, size_nums);
    
    for(int i=0; i<size_nums;i++)
    {
        printf("%d", *(nums+i));

    }
    
    return 0;
}
