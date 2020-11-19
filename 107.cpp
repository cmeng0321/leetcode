/*
107. Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

solve
定义两个queue
一个用来存储将要向vector存值的层所有的节点，一个用来访问取值时边取边暂存节点为加载下一层的节点做准备 
从上往下存（.push_front()不能用） 
由于最后一层完成后还存下了一层NULL，因此倒序时.end()-2 
中间也会存在NULL，因此取值时注意判断是否为NULL 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> vec0;
        vector<vector<int>> vec;
        if(!root) {
            
            return vec;
        }
        queue<TreeNode*> tree;
        tree.push(root);
        while(!tree.empty()){
            queue<TreeNode*> tree_tmp;
            vec0.clear();
            while(!tree.empty()){
                if(tree.front()){
                    TreeNode* node = tree.front();
                    vec0.push_back(node->val);
                    tree_tmp.push(tree.front());
                }
                tree.pop();
            }
            vec.push_back(vec0);
            while(!tree_tmp.empty()){
                if(tree_tmp.front()){
                    tree.push(tree_tmp.front()->left);
                    tree.push(tree_tmp.front()->right);
                }
                tree_tmp.pop();
            }
        }
        
        vector<vector<int>> vect;
        vector<vector<int>>::iterator iter;
        for(iter = vec.end()-2; iter >= vec.begin(); iter--){
            vect.push_back(*iter);
        }
        return vect;
    }
};
