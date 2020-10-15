/*
38. Count and Say
The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.
Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"
Explanation: This is the base case.

Example 2:
Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".

solve
两个循环
第一个循环：要的第几个值
第二个循环：看上一个的输出，在本层该如何表示 
 用 num计数 ：相同的加 1；不同了将num,c存入 say，然后重置num,c
 最后一位的相关未存入say，第二层循环外存入，且重置count，say。 
*/ 

class Solution {
public:
    string countAndSay(int n) {
        string count = "1";
        string say; 
        
        if(n == 1){
            return count;
        }
        
        int i;
        for(i = 1; i < n; i++){
            int num = 0;
            char c = count[0];
            int j;
            for(j = 0; j < count.size(); j++){
                if(c == count[j]){
                    num++;
                    continue;
                }
                else{
                    say.insert(say.size(), 1, '0'+num);
                    say.insert(say.size(), 1, c);
                    
                    num = 0;
                    c = count[j];
                    num++;
                }
                
            }
       
			say.insert(say.size(), 1, '0'+num);
            say.insert(say.size(), 1, c);
            count = say;
            say = "";
        }
        return count;
    }
};
