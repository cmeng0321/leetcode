/*
167. Two Sum II - Input array is sorted
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
Note:
Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
 
Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
 
Constraints:
2 <= nums.length <= 3 * 104
-1000 <= nums[i] <= 1000
nums is sorted in increasing order.
-1000 <= target <= 1000

solve
��һ��ǰ����Ϊ��׼���ҵڶ������� ��Time Limit Exceeded����һЩ��������
�ڶ���ǰ��һ�鿪ʼ����targetС�ˣ���һ����ǰ�ƣ����ˣ��ڶ��������� 
*/ 

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> vect;
        
        int temp1=10000,temp2=10000;
        int i, j;
        for(i = 0; i < numbers.size() - 1; ++i){
            if(numbers[i] == temp1){
                continue;
            }
            if(numbers[i] > 0 && numbers[i] > target) break;
            for(j = i+1; j < numbers.size(); ++j){
                if(numbers[j] == temp2) continue;
                
                if(numbers[i] + numbers[j] == target){
                    vect.push_back(i+1);
                    vect.push_back(j+1);
                    return vect;
                }
                else if(numbers[i] + numbers[j] < target) continue;
                else break;
                
                temp2 = numbers[j];
            }
            temp1 = numbers[i];
        }
        return vect;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> vect;
        int i, j;
        for(i = 0, j = numbers.size()-1; i < j;){
            if(numbers[i] + numbers[j] == target){
                vect.push_back(i+1);
                vect.push_back(j+1);
                return vect;
            }
            else if(numbers[i] + numbers[j] < target) ++i;
            else --j;
            
        }
        return vect;
    }
};
