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
��һ�֣�������������м��Ϊ����ֵ��ż�����м���������Ϊ����ֵ ����ʱ 
�ڶ��֣��ҳ�һ�鲻ͬ��Ԫ�������������ɾ�������ֻ��ʣ��һ��Ԫ�� 
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
