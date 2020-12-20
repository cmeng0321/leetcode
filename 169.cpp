/*
169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2

solve
第一种：排序后，奇数个中间的为返回值，偶数个中间两个均可为返回值 ，费时 
第二种：找出一组不同的元，将其从数组中删除，最后只会剩下一种元素 
*/ 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        return nums[(nums.end()-nums.begin())/2];
    }
    
        int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int flag = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(num == nums[i]){
                ++flag;
            }
            else if(flag == 0){
                num = nums[i];
                ++flag;
            }
            else --flag;
        }
        return num;
    }
};
