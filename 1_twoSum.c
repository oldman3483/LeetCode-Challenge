// brutal 

int* twoSum(int nums[], int numsSize, int target) {

    int result;
    int *index = malloc(sizeof(int)*2);
    
    for(int i=0; i<numsSize; i++)
    {
        for(int j=i+1; j<numsSize; j++)
        {
            result = nums[i]+nums[j];
            if(result == target)
            {
                index[0] = i;
                index[1] = j;
                return index; 
                
            }
        }
    }
    
    return NULL;
}


// hash

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    // find the Max and Min => know the array size sou need
    int max=nums[0],min=nums[0],i;
    for(i=1;i<numsSize;i++){
        max=max>nums[i]?max:nums[i];
        min=min<nums[i]?min:nums[i];
    }


    int arrsize=max-min+1;
    int *HT=calloc(arrsize--,sizeof(int));
    HT[nums[0]-min]=-1;
    for(i=1;i<numsSize;i++){
        HT[nums[i]-min]=i;
    }
    *returnSize=2;
    int *ret=(int*) malloc(2*sizeof(int)),index2;
    for(i=0;i<numsSize;i++){
        index2=target-nums[i]-min;
        if(index2<0||index2>arrsize)continue;
        if(HT[index2]){
            ret[0]=i;
            ret[1]=HT[index2];
            if(HT[index2]<0)ret[1]=0;
            if(ret[0]==ret[1]){
                continue;
            }
            free(HT);
            return ret;
        }
    }
    return 0;
}