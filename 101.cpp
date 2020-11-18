/*
101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

solve
��������queue�����洢��һ���ڵ�����������£���ߵ��ȴ�����ң��ұߵ��ȴ��Һ��󣬱�֤�洢�Գ� 
�������ڵ�һ�����ڣ�һ��������ʱ��˵����ͬ
�������ڵ��������ʱ��Ҫ��������ж�
�������ڣ��ж�val  
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if(!(root->right)&&!(root->left)) return true;
        
        TreeNode* v1;
        TreeNode* v2;
        
        queue<TreeNode*> tree1;
        queue<TreeNode*> tree2;
        tree1.push(root->left);
        tree2.push(root->right);
        v1 = tree1.front();
        v2 = tree2.front();
        while(!tree1.empty()){
            tree1.pop();
            tree2.pop();
            if((!v1&&v2)||(v1&&!v2)) return false;
            if(!v1&&!v2){
                v1 = tree1.front();
                v2 = tree2.front();
                continue;
            }
            if(v1->val != v2->val) return false;
            tree1.push(v1->left);
            tree1.push(v1->right);
            tree2.push(v2->right);
            tree2.push(v2->left);
            
            v1 = tree1.front();
            v2 = tree2.front();
        }
        return true;
    }
};
