/*
35. Search Insert Position
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0

solve
���αȽ� 
*/ 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.front() > target) return 0;
        if(nums.back() < target) return int(nums.size());
        vector<int>::size_type iter;
        for(iter = 0; iter < nums.size(); iter++){
            if(nums[iter] < target) continue;
            else if(nums[iter] >= target) return int(iter);
        }
        return int(iter);
    }
};
