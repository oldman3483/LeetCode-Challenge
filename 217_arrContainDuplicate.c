

// BRUTAL SOLN: FAIL TIME LIMITED O(n^2)
bool containsDuplicate(int* nums, int numsSize){
    for(int i=0; i<numsSize; i++)
    {
        for(int j=i+1; j<numsSize; j++)
        {
            if(nums[i] == nums[j])
                return true;
        }
    }
    return false;
}


// SORT O(nlogn)
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

void Qsort(int* nums, int left, int right)
{
    if (right > left)
    {
        int i = left-1;
        int j = right+1;
        int s = nums[(left+right)/2];

        while(1)
        {
            while(nums[++i] < s);
            while(nums[--j] > s);
            if (i >= j)
                break;
            swap(&nums[i], &nums[j]);
        }
        Qsort(nums, left, i-1);
        Qsort(nums, j+1, right);
    }

}

bool containsDuplicate(int* nums, int numsSize){

    int i = 0;
    Qsort(nums, 0, numsSize-1);
    while(i+1 < numsSize)
    {
        if(nums[i] == nums[i+1])
            return true;
        i++;
    }
    return false;
}


// HASH O(n)

bool containsDuplicate(int* nums, int numsSize){

}
