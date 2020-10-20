/*
58. Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
If the last word does not exist, return 0.
Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:
Input: "Hello World"
Output: 5

solve
字符串中的字符一个一个比较，为了防止字符串后面的空格将字符串刷掉，定义一个中间字符串在判断过程中存字符，只有当新的字符串不是空的时候替换准备输出的字符串 
因为有个中间字符串用于存字符，当最后一位是字符时，还未更新到目标字符串中 
 
*/ 

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) return 0;
        
        string str, temp;
        int i;
        int count = 0;
        for(i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                temp.insert(count, 1, s[i]);
                count++;
            }
            else{
                if(!temp.empty()) str = temp;
                temp = "";
                count = 0;
            }
        }
        if(!temp.empty()) str = temp;
        return str.size();
    }
};
