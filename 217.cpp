/*
217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true

Example 2:
Input: [1,2,3,4]
Output: false

Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

solve
用set存储已读数据，在set中查找是否有将读数，有返回true，否则存入set中

另一种方法对vector中的数排序，看是否有相连续的数相等 

将vector中的值全存入set，因为set中不存在相同的key，因此当有相同数时，vector的size大于set的size 
*/ 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0 ||nums.size() == 1) return false;
        set<int> s;
        s.insert(nums[0]);
        for(int i = 1; i < nums.size(); ++i){
            if(s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);  
        }
        return false;
    }
    
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0 ||nums.size() == 1) return false;
        sort(nums.begin(), nums.end()); 
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
	
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }	    
};
