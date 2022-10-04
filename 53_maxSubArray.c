#define MAX(x, y) x>y?x:y;
// Greedy 
int maxSubArray(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    
    int curr = 0;
    int maxSum = nums[0];

    for(int i=0; i<numsSize; i++)
    {
        curr = MAX(nums[i]+curr, nums[i]);
        maxSum = MAX(maxSum, curr);
    }
    return maxSum;
    
}