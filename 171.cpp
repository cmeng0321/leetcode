/*
171. Excel Sheet Column Number
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
    
Example 1:
Input: "A"
Output: 1

Example 2:
Input: "AB"
Output: 28

Example 3:
Input: "ZY"
Output: 701
 
Constraints:
1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW".

solve
倒着算，用tmp标记该位的倍数 
正着算 ，加上该位时，需对前面的和乘26 
*/ 

class Solution {
public:
    int titleToNumber(string s) {
        int sum = s.back() - 'A' + 1;
        
        int tmp = 1;
        for(int i = s.size() - 2 ; i >= 0 ; --i){
            tmp = tmp * 26;
            sum += (s[i] - 'A' + 1) * tmp;
        }
        return sum;
    }
    
    int titleToNumber(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); ++i){
            sum = sum * 26 + (s[i] - 'A' + 1);
        }
        return sum;
    }    
};
