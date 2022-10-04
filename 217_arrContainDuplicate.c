

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

void qsort(int* nums, int left, int right)
{
    int i = left-1;
    int j = right+1;
    int pIdx = 1/2*(left+right);

    while(1)
    {
        while(nums[++i] < nums[pIdx]);
        while(nums[++j] > nums[pIdx]);
        if (i >= j)
            break;
        swap(nums[i], nums[j]);
    }
    qsort(nums, left, pIdx-1);
    qsort(nums, pIdx+1, right);

}
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 


void quickSort(int number[], int left, int right) { 
    if(left < right) { 
        int s = number[(left+right)/2]; 
        int i = left - 1; 
        int j = right + 1; 

        while(1) { 
            while(number[++i] < s) ;  // 向右找 
            while(number[--j] > s) ;  // 向左找 
            if(i >= j) 
                break; 
            SWAP(number[i], number[j]); 
        } 

        quickSort(number, left, i-1);   // 對左邊進行遞迴 
        quickSort(number, j+1, right);  // 對右邊進行遞迴 
    } 
} 
bool containsDuplicate(int* nums, int numsSize){

    int i = 0;
    quickSort(nums, 0, numsSize-1);
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
