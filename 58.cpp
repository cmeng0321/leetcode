/*
58. Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
If the last word does not exist, return 0.
Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:
Input: "Hello World"
Output: 5

solve
�ַ����е��ַ�һ��һ���Ƚϣ�Ϊ�˷�ֹ�ַ�������Ŀո��ַ���ˢ��������һ���м��ַ������жϹ����д��ַ���ֻ�е��µ��ַ������ǿյ�ʱ���滻׼��������ַ��� 
��Ϊ�и��м��ַ������ڴ��ַ��������һλ���ַ�ʱ����δ���µ�Ŀ���ַ����� 
 
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
