int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *auxiliary = (int*)malloc(2 * sizeof(int));

    for(int i = 0;i < numsSize;i++){
        for(int j = i + 1;j < numsSize;j++){
            if(*(nums + i) + *(nums + j) == target)
            {
                *(auxiliary + 0) = i;
                *(auxiliary + 1) = j;

                *returnSize = 2;
                
                return auxiliary;
            }
        }
    }
    free(auxiliary);
    return NULL;
}
