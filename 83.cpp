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
����һ��node�������м���ֵ��ɾ�� 
ȡ��һ���ڵ��ֵ��Ȼ��ȡ��һ�������жϣ�ѡ����ֲ���
����ͬʱ��ʹ��һ���ڵ��ֵָ�����¸����ټ����Ƚ�
����ͬʱ��������Ҫ�Ƚϵ�ֵ 
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
