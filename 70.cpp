/*
70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

solve
取出1或者2，成为两种方式，可认为将（n-1）和（n-2）的相加 
尝试第一种迭代将花费过长时间 ，可认为倒着来的 
第二种认为一种顺着来的 
*/ 

class Solution {
public:
    int climbStairs(int n) {
        int num = 0;
        if(n==1) return 1;
        if(n==2) return 2;
        num = num + climbStairs(n-1)+ climbStairs(n-2);
        return num;
    }
	
	int climbStairs(int n) {
        int num = 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int num1 = 1;
        int num2 = 2;
        int i;
        for(i = 3; i <= n; i++){
            num = num1 + num2;
            num1 = num2;
            num2 = num;
        }
        return num;
    }
};
