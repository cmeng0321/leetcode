/*
26. Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
It doesn't matter what values are set beyond the returned length.

solve
当数字第一次出现时保留，记录下数值以便和后面的进行比较
 
*/ 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //int flag = 0;
        vector<int>::iterator i = nums.begin();
        for(vector<int>::iterator iter = nums.begin()+1; iter < nums.end();)
        {
            
            if(*i == *iter){
                iter = nums.erase(iter);
                    
            }
            else{
                i = iter;
                ++iter;
            }
        }
        
        return nums.size();
    }
};
