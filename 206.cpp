/*
206. Reverse Linked List
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?

solve
׼��һ���սڵ㵹����֯ 
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
    ListNode* reverseList(ListNode* head) {
        ListNode* head0 = new ListNode;
        head0 = NULL;
        while(head){
            ListNode* tmp = head->next;
            head->next = head0;
            head0 = head;
            head = tmp;
        }
        return head0;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* head0 = new ListNode;
        head0 = NULL;
        while(head){
            ListNode* tmp = head;
            head = head->next;    //����tmp->next = head0֮ǰ������ᶪʧ����ڵ� 
            tmp->next = head0;
            head0 = tmp;
        }
        return head0;
    }
};
