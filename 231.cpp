/*
231. Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:
Input: n = 3
Output: false

Example 4:
Input: n = 4
Output: true

Example 5:
Input: n = 5
Output: false
 
Constraints:
-231 <= n <= 231 - 1

solve
对n循环判断是否为2的倍数且除以2，为1的时候跳出返回true
n <= 0 时返回false 

位操作，二进制表示位置只有最高位为1 则(n&n-1)==0
或数1的个数 
*/ 

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        while(n>1){
            if(n % 2 != 0) return false;
            n = n / 2;
        }
        return true;
    }
    
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return !(n&(n-1));
    }  
};
