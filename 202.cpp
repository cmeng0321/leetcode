/*
202. Happy Number
Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:
Input: n = 2
Output: false
 
Constraints:
1 <= n <= 231 - 1

solve
将每次准备拆分的值存入一个vector中，如果新加到的值在vector中存在，则返回false，新值为1，返回true ；
也可用其他容器存 
*/ 

class Solution {
public:
    bool isHappy(int n) {
        vector<int> nums;
        nums.push_back(n);
        while(1){
            int m = 0;
            while(n){
                int tmp = n % 10;
                m += tmp * tmp;
                n = n / 10;
            }
            if(m == 1) return true;
            
            //vector<int>::iterator 
            if(find(nums.begin(), nums.end(), m) != nums.end()) break;
            n = m;
            nums.push_back(n);
        }
        return false;
    }
};
