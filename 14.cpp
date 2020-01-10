/*
14. Longest Common Prefix
	
	Write a function to find the longest common prefix string amongst an array of strings.
	If there is no common prefix, return an empty string "".

	Example 1:
	Input: ["flower","flow","flight"]
	Output: "fl"

	Example 2:
	Input: ["dog","racecar","car"]
	Output: ""
	Explanation: There is no common prefix among the input strings.

	Note:
	All given inputs are in lowercase letters a-z.
*/
 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i,j,flag,l;
        char basec, comparec;
        string s;
        
        if(strs.empty()) {return s;}
        else if(strs.size() == 1) {return strs[0];}
        
        flag = 1;
        const char *c = strs[0].c_str();
        l = strlen(c);
        for(i = 0; i < strlen(c); i++)
        {
            basec = c[i];
            for(j = 1; j < strs.size(); j++)
            {
                const char *c1 = strs[j].c_str();
                comparec = c1[i];
                if(basec != comparec)
                {
                    flag = 0;
                    break;
                }
            }
            
            if(flag != 1)
            {
                l = i;
                break;
            }
        }
        
        s = strs[0];
        s.erase(l+s.begin(), s.end());
        return s;
    }
};
