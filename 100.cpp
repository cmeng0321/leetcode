/*
100. Same Tree
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]
Output: true

Example 2:
Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]
Output: false

Example 3:
Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]
Output: false

solve
��������queue�����洢��һ��Ҫ���ʵĽڵ㣬��֤���������Ƚϵ�λ����ͬ
�������ڵ�һ�����ڣ�һ��������ʱ��˵����ͬ
�������ڵ��������ʱ��Ҫ��������ж�
�������ڣ��ж�val 
 
*/ 

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((!p&&!q)) return true;
        if((!p&&q)||(p&&!q)) return false;
        
        TreeNode* v1;
        TreeNode* v2;   //�ɲ����壬ֱ��ʹ�� p��q 
        
        queue<TreeNode*> tree1;
        queue<TreeNode*> tree2;
        tree1.push(p);
        tree2.push(q);
        v1 = tree1.front();
        v2 = tree2.front();
        while(!tree1.empty()){
            
            tree1.pop();
            tree2.pop();
            if((!v1&&v2)||(v1&&!v2)) return false;
            if((!v1&&!v2)) {
                v1 = tree1.front();
                v2 = tree2.front();
                continue;
            }
            if(v1->val != v2->val) return false;
            
            tree1.push(v1->left);
            tree1.push(v1->right);
            tree2.push(v2->left);
            tree2.push(v2->right);
            
            v1 = tree1.front();
            v2 = tree2.front();
            
        }
        
        return true;
    }
};
