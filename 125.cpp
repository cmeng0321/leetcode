/*
125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false
 

Constraints:
s consists only of printable ASCII characters.

solve
在循环中判断，当对称不等时，返回false
当跳出循环时，偶数个已全对比，奇数个只剩下中间一位 ，返回true 
*/ 

class Solution {
public:
    bool isPalindrome(string s) {
        int i,j;
        for(i = 0, j = s.size()-1; i < j;){
            if(s[i] < '0' || (s[i] > '9' && s[i] < 'A') || ('Z' < s[i] && s[i] < 'a') || s[i] >'z'){
                ++i;
                continue;
            }
            if(s[j] < '0' || (s[j] > '9' && s[j] < 'A') || ('Z' < s[j] && s[j] < 'a') || s[j] >'z'){
                --j;
                continue;
            }
            
            if(s[i] < 'a') s[i] = s[i] + 32;
            if(s[j] < 'a') s[j] = s[j] + 32;
            
            if(s[i] != s[j]) return false;
            else{
                ++i;
                --j;
            }
        }
        
        return true;
    }
};
