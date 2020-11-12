/*
83. Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3

solve
另设一个node，调节中间数值的删除 
取第一个节点的值，然后取下一个进行判断，选择何种操作
当相同时，使第一个节点的值指向下下个，再继续比较
当不同时，调整需要比较的值 
*/ 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        int x = head->val;
        ListNode *node = head;
        int y;
        while(node->next){
            y = node->next->val;
            if(x != y){
                x = y;
                node = node->next;
                continue;
            }
            else{
            
                node->next = node->next->next;
            }
        }
        return head;
    }
};
