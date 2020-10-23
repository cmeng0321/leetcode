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
倒叙
当最后一位为9时，说明要向前一位进 1，令flag=1 
对于除最后的每一位，判断flag是否为 1，从而判断是否要加 1（加 1时，需判断是否是 9，造成进位；不加 1，即flag=0，可直接出循环）
对于出循环后flag=1的情况（有进位），说明前面需要补一位 1。 
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
