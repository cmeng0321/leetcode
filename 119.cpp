/*
119. Pascal's Triangle II
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
Notice that the row index starts from 0.
In Pascal's triangle, each number is the sum of the two numbers directly above it.
Follow up:
Could you optimize your algorithm to use only O(k) extra space?

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]

Constraints:
0 <= rowIndex <= 33

solve
第一种：一层一层向下算，每行从前往后计算，速度慢，需要较多空间
第二种： 一层一层向下算，每行从后往前算，可直接在原vector上进行操作 
*/ 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        vec.push_back(1);
        if(rowIndex == 0) return vec;
        
        vec.push_back(1);
        if(rowIndex == 1) return vec;
        
        for(int i = 1; i < rowIndex; ++i){
            vector<int> vec_tmp;
            vector<int>::iterator iter;
            
            vec_tmp.push_back(1);
            for(iter = vec.begin(); iter < vec.end()-1; ++iter){
                vec_tmp.push_back(*iter+*(iter+1));
            }
            vec_tmp.push_back(1);
            vec = vec_tmp;
        }
        return vec;
    }
    
    vector<int> getRow(int rowIndex) {
        vector<int> vec(rowIndex+1);
        vec[0] = 1;
        if(rowIndex == 0) return vec;
        
        vec[1] = 1;
        if(rowIndex == 1) return vec;
        
        for(int i = 2; i <= rowIndex; ++i){
            for(int j = i; j >= 1; --j){
                vec[j] += vec[j-1];
            }
        }
        return vec;
    }
};
