/*
168. Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
    
Example 1:
Input: 1
Output: "A"

Example 2:
Input: 28
Output: "AB"

Example 3:
Input: 701
Output: "ZY"

solve
以A-Z，26个字母为循环
若直接对26操作，26会出错 
可在为26倍数时另操作
也可在每次计算新一位前--n 
*/ 

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n > 0){
            if(n % 26 == 0){
                s.insert(0, 1, 'Z');
                n = n / 26 - 1;
            }
            else{
                
                s.insert(0, 1, 'A' + n % 26 - 1);
                n = n / 26;
            }       
        }
        return s;
    }    
	
	string convertToTitle(int n) {
        string s;
        while(--n >= 0){
            if(n % 26 == 0){
                s.insert(0, 1, 'A');
            }
            else{
                s.insert(0, 1, 'A' + n % 26);
            }
            n = n / 26;    
        }
        return s;
    }
};
