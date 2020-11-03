/*
67. Add Binary
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:
Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.

solve
以较长的为基准，短的字符串中的字符从后往前一次计算
计算过程中可当做数字相加，和是否大于1看是否进位 
较短的计算完成后继续对较长的字符串剩余的判断，不进位了就可退出
最后 如果已经跳出循环仍要进位，字符串首尾需要补1 
*/ 

class Solution {
public:
    string addBinary(string a, string b) {
        string temp;
        if(a.size()<b.size()){
            temp = a;
            a = b;
            b = temp;
        }
        
        int i, j;
        int sub = 0;
        char aa, bb;
        int sum;
        for(i = b.size() - 1, j = a.size() - 1; i >= 0; i--, j--){
            aa= a[j];
            bb= b[i];
            
            sum = aa - '0' + bb - '0' + sub;
            
            if(sum > 1){
                sub = 1;
                a[j] = '0' + sum % 2;
            }
            else{
                sub = 0;
                a[j] = '0' + sum;
            }
            
        }
        
        for(; j >= 0; j--){
            aa= a[j];
            sum = aa - '0' + sub;
            
            if(sum > 1){
                sub = 1;
                a[j] = '0' + sum % 2;
            }
            else{
                sub = 0;
                a[j] = '0' + sum;
                break;
            }
        }
        
        if(sub == 1) a.insert(0, 1, '1');
        return a;
    }
};
