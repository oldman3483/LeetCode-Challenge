#include <stdio.h>
#include <stdlib.h>


int dominantIndex(int* nums, int numsSize){
    int *num_index = malloc(100*sizeof(int));
    int max=0;
    int max2=0;
    int out=0;
    int num_init = 0;
    if (numsSize == 1)
        return 0;
    for (int j = 0; j<100; j++)
    {
        num_index[j] = -1;
    }
    for (int i = 0; i<numsSize; i++)
    {
        num_init = nums[i];
        if (*(nums+i) > max)
        {
            max2 = max;
            max = nums[i];
            //printf("check \n");
        }else if(*(nums+i)>max2)
        {
            max2 = nums[i];
        }
        num_index[num_init] = i;
        //printf("max=%d, max2=%d\n", max, max2);
    }
    if (max >= max2*2)
    {
        out = num_index[max];
        return out;
    }
    return -1;
}

int main(void)
{    
    int nums1[8] = {1,2,16,35,44,100,27,0};
    int nums2[8] = {0,0,3,2};
    int out;
    out = dominantIndex(nums1, 8);
    printf("%d\n", out);
}