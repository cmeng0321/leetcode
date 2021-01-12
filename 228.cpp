/*
228. Summary Ranges
You are given a sorted unique integer array nums.
Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:
"a->b" if a != b
"a" if a == b
 
Example 1:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

Example 3:
Input: nums = []
Output: []

Example 4:
Input: nums = [-1]
Output: ["-1"]

Example 5:
Input: nums = [0]
Output: ["0"]
 
Constraints:
0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.

solve
直到一个不连续的数时，在字符串s中加入箭头以及转换成字符串的数字
考虑可能出现的情况 
*/ 

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string s;
        string ss;
        vector<string> str;
        int flag = 0;
        if(nums.empty()) return str;
        
        int tmp = nums[0];
        int temp;
        if(tmp == 0) s.insert(0, 1, '0');
        else{
            ss = to_string(tmp);
            s.insert(s.size(), ss); 
        }
        ss.clear();
        
        for(int i = 1; i < nums.size(); ++i){
            
            if(nums[i-1]+1 != nums[i]){
                if(flag == 0){
                    str.push_back(s);
                    ss.clear();
                    s.clear();
                    tmp = nums[i];
                    ss = to_string(tmp);
                    s.insert(s.size(), ss);
                    ss.clear();
                    flag = 0;
                    continue;
                }
                tmp = nums[i-1];
                
                ss = to_string(tmp);
                s.insert(s.size(), "->");
                s.insert(s.size(), ss);
                
                str.push_back(s);
                s.clear();
                ss.clear();
                
                tmp = nums[i];
                ss = to_string(tmp);
                s.insert(s.size(), ss);
                ss.clear();
                flag = 0;
                continue;
            }
            else{
                flag = 1;
            }

        }
        if(flag == 1){
            tmp = *--nums.end();
            ss = to_string(tmp);
            s.insert(s.size(), "->");
            s.insert(s.size(), ss);
        }
        if(!s.empty()) str.push_back(s);
        return str;
    }
};
