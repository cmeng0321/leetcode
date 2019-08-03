/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        deque<TreeNode*> dq;
        vector<int> v1,v2;
        while(true)
        {
            int flag1=1,flag2=1;
            if (root1->right) dq.push_front(root1->right);
            else flag1=0;
            if (root1->left) dq.push_front(root1->left);
            else flag2=0;
            if(flag1==0 && flag2==0) v1.push_back(root1->val);
            if (dq.empty()) break;
            root1 = dq.front();
            dq.pop_front();
        }
        while(true)
        {
            int flag1=1,flag2=1;
            if (root2->right) dq.push_front(root2->right);
            else flag1=0;
            if (root2->left) dq.push_front(root2->left);
            else flag2=0;
            if(flag1==0 && flag2==0) v2.push_back(root2->val);
            if (dq.empty()) break;
            root2 = dq.front();
            dq.pop_front();
        }
        if(v1==v2) return true;
        else return false;
    }
};
