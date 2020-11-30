/*
118. Pascal's Triangle
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

solve
��һ���п�ʼ�����úã���Ҫע�⵱ Numrows=0/1ʱ�ķ���
ѭ���Ľ�������ע�⣬��Ϊȡֵ�Ǽ����е�ǰһ�� 
*/ 

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> vec;
        vector<vector<int>> vect;
        if(numRows == 0) return vect;
        
        vec.push_back(1);
        vect.push_back(vec);
        if(numRows == 1) return vect;
        vec.push_back(1);
        vect.push_back(vec);
        for(int i = 1; i < numRows-1; ++i){
            vec.clear();
            
            vec.push_back(1);
            vector<int>::iterator j;
            for(j = (*(vect.begin()+i)).begin(); j < (*(vect.begin()+i)).end()-1; ++j){
                vec.push_back(*j + *(j+1));
            }
            vec.push_back(1);
            vect.push_back(vec);
        }
        return vect;
    }
};
