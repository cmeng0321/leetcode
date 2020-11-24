/*
108. Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
      0
     / \
   -3   9
   /   /
 -10  5

solve
选取中间的值作为跟节点
对左右两个子节点分别调用原函数，函数的参数vector分别为以跟节点划分的两个vector 
注意vector是否还存在 
*/ 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* tree = new TreeNode;
        if(nums.empty()) return NULL;
        if(nums.size()== 1){
            tree->val = nums.front();
            return tree;
        }
        
        
        vector<int>::iterator iter = nums.begin()+(nums.end()-nums.begin())/2;
        vector<int> num_tmp;
        tree->val = *iter;
        if(iter > nums.begin()){
            num_tmp.assign(nums.begin(),iter);
            tree->left = sortedArrayToBST(num_tmp); 
        }
        if(iter < nums.end()-1){
            num_tmp.assign(iter+1,nums.end());
            tree->right = sortedArrayToBST(num_tmp);
        }
        
    
        return tree;
    }
};
