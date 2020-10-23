/*
66. Plus One
Given a non-empty array of digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

Example 3:
Input: digits = [0]
Output: [1]

solve
����
�����һλΪ9ʱ��˵��Ҫ��ǰһλ�� 1����flag=1 
���ڳ�����ÿһλ���ж�flag�Ƿ�Ϊ 1���Ӷ��ж��Ƿ�Ҫ�� 1���� 1ʱ�����ж��Ƿ��� 9����ɽ�λ������ 1����flag=0����ֱ�ӳ�ѭ����
���ڳ�ѭ����flag=1��������н�λ����˵��ǰ����Ҫ��һλ 1�� 
*/ 

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag;
        vector<int>::iterator iter = digits.end() - 1;
        if(*iter == 9){
            flag = 1;
            *iter = 0;
        }
        else{
            ++digits.back();
            flag = 0;
        }   
        for(vector<int>::iterator iter = digits.end() - 2; iter >= digits.begin(); iter--){
            if(flag == 0){
                break;
            }
            else{
                if(*iter == 9){
                    flag = 1;
                    *iter = 0;
                }
                else{
                    ++(*iter);
                    flag = 0;
                } 
                    
            }
        }
        if(flag == 1) digits.insert(digits.begin(),1);
        return digits;
    }
};
