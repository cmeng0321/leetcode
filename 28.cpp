/*
28. Implement strStr()
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

solve
��haystackΪ��׼ƥ�䣬needle������index��ʼһֱΪ0�������ֵ�һ��ƥ���index���ӣ�
���м���ֲ�ƥ����ַ���haystack�������践�ص��˴ο�ʼƥ����ַ�����һ����index��Ϊ0�����¿�ʼƥ�� 
������num��index����Ϊһ�� 
*/ 

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty()) return -1;
        int num = 0;
        int index = 0;
        int i = 0;
        for(i; i < haystack.size();i++){
            if(haystack[i] == needle[index]){
                num++;
                index++;
                if(num == needle.size()) return i - needle.size() + 1;
            }
            else{
                if(num > 0) i = i - num;
                num=0;
                index = 0;
            }
            
        }
        if(num == needle.size()) return i - needle.size();
        return -1;
    }
};
