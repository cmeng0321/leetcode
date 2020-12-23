/*
203. Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

solve
使用node->next作为循环判断条件，以便去掉当前next
因为是判断node->next，所以开始的node并未判断，因此开始就循环判断前面的是否等于val，不等于后在进入另一个循环 

也可使用递归，依次判断当前第一个节点是否需要保留
依次判断最后一个是否需要保留 
*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        
        while(head->val == val){
            head = head->next;
            if(!head) return head;
        }
        
        ListNode* node = head;
        
        while(node->next){
            if((node->next)->val == val){
                if(node->next->next){
                    node->next = node->next->next;
                }
                else{
                    node->next = NULL;
                    break;
                } 
            }
            else{
                node = node->next;
            }
        }
        return head;
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        
        if(head->val == val) head = removeElements(head->next, val);
        else head->next = removeElements(head->next, val);
        return head;
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next: head;
    }
};
