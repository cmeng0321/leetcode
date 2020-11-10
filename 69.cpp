/*
69. Sqrt(x)
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:
Input: 4
Output: 2

Example 2:
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.

solve
1 直接调用sqrt函数
2 循环判断 
*/ 

class Solution {
public:
    int mySqrt(int x) {
        int i = sqrt(x);
        return i;
    }
	
	int mySqrt(int x) {
        if(x == 0) return 0;
        int i = 1;
        while(x > 0){
        	int j = x / i;
        	if(j < i){
        		i--;
				break;
			}
        	else if(j == i){
        		break;
			}
			
			i++;
		}
        return i;
    }
};
