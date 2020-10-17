/*
53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [0]
Output: 0

Example 4:
Input: nums = [-1]
Output: -1

Example 5:
Input: nums = [-2147483647]
Output: -2147483647

Constraints:
1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1

solve
分为两部分：当即将加的数大于0时（直接加或者只要当前值）
当即将加的数小于0时（首先要考虑原sum是否为当前的最大值而存下来，直接加或者只要当前值） 
*/ 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        int sum = nums[0];
        int temp = -2^31;
        for(vector<int>::iterator iter = nums.begin()+1; iter < nums.end(); iter++){
            if(sum + *iter < sum){
                if(temp < sum) temp = sum;
                
                if(sum < 0) sum = *iter;
                else sum = sum + *iter;
            }
            else{
                if(sum < 0) sum = *iter;
                else sum = sum + *iter;
            }
            
        }
        if(temp < sum) return sum;
        else return temp;
    }
};
