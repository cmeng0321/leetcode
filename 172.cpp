/*
172. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.
Follow up: Could you write a solution that works in logarithmic time complexity?

Example 1:
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Example 3:
Input: n = 0
Output: 0
 
Constraints:
0 <= n <= 104

solve
末尾为0，即要和数字5相关
判断包含多少个5，特别注意有的数字包含不止一个5 
*/ 

class Solution {
public:
    int trailingZeroes(int n) {
        int num = 0;
        while(n){
            num += n / 5;
            n = n / 5;
        }
        return num;
    }
};
