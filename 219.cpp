/*
219. Contains Duplicate II
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

solve
���жϸ�ֵ��ǰ���Ƿ�����ȵ�ֵ�����е�������ж��Ƿ񲻳��� k, �ڲ�����������»���Ҫ����ֵ�Ƿ񻹴��ڸ�����
1��ѭ����
2������ɾ���ԱȽϵ�ֵ��ǰ�����

����unordered_map 
*/ 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0 || nums.size() == 1) return false;
        
        if(nums.size() == set(nums.begin(), nums.end()).size()) return false;
        int num = 0;
        vector<int>::iterator iter = nums.begin() + 1;
        for(; iter < nums.end(); ++iter){
            if(find(nums.begin(), iter, *iter) != iter){
                vector<int>::iterator tmp = find(nums.begin(), iter, *iter);
                int di = iter - tmp;
                if(di <= k) return true;
                while(1){
                    if(find(tmp + 1, iter, *iter) != iter){
                        tmp = find(tmp + 1, iter, *iter);
                        di = iter - tmp;
                        if(di <= k) return true;
                    }
                    else break;
                }
                
            }
        }
        return false;
        
    }	
	
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0 || nums.size() == 1) return false;
        
        if(nums.size() == set(nums.begin(), nums.end()).size()) return false;
        vector<int>::iterator iter = nums.begin() + 1;
        for(; iter < nums.end(); ){
            if(find(nums.begin(), iter, *iter) != iter){
                vector<int>::iterator tmp = find(nums.begin(), iter, *iter);
                int di = iter - tmp;
                if(di <= k) return true;
                else{
                    nums.erase(nums.begin(), tmp+1);
                    iter = nums.begin() + 1;
                    continue;
                }
                
            }
            else ++iter;
        }
        return false;
        
    }
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            if(m.find(nums[i]) != m.end()){
                if(i - m[nums[i]] <= k) return true;
            }
            m[nums[i]] = i;   //�����ֵ��λ�ã����߸����˾������kʱ��ֵ��λ�ã��Ա�����Ƚϼ��� 
        }
        return false;
    }
};
