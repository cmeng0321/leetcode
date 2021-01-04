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
��set�洢�Ѷ����ݣ���set�в����Ƿ��н��������з���true���������set��

��һ�ַ�����vector�е������򣬿��Ƿ���������������� 

��vector�е�ֵȫ����set����Ϊset�в�������ͬ��key����˵�����ͬ��ʱ��vector��size����set��size 
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
