/*
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:
Input: s = ""
Output: 0
 
Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

solve
����һ��string�浱ǰ�������ظ����ַ�
�����ַ������ڣ����� 
��һ�����ַ��Ѵ��ڣ�ɾȥ����ַ�һ�����ַ���ǰ����ַ����Ҵ�����ַ�
�ж�lengthֵ���ַ����ȣ� 
*/ 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        string s_tmp;
        int length = 0;
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            int j;
            for(j = 0; j < s_tmp.size(); ++j){
                if(s_tmp[j] == c){
                    //length = length>s_tmp.size() ? length : s_tmp.size();
                    s_tmp.erase(0,s_tmp.find(c)+1);
                    break;
                }
            }
            s_tmp.push_back(c);
            length = length>s_tmp.size() ? length : s_tmp.size();
        }
        return length;
    }
};
