/*
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

solve
需要考虑到三种情况两个等长，l1长于l2，l1短于l2
flag标志有无进位 
middle->next判断以便在最后若要加上一位可给当前节点续接 
*/ 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1;
        int num2;
        int flag = 0;
        ListNode *middle = l1;
        
        while(middle->next && l2->next){
            num1 = middle->val;
            num2 = l2->val;
            if(flag == 0){
                num1 = num1 + num2;
            }
            else{
                num1 = num1 + num2 + 1;
            }
            if(num1 > 9){
                flag = 1;
                num1 = num1 % 10;
            }
            else flag = 0;
            middle->val = num1;
            middle = middle->next;
            l2 = l2->next;
        }
        
        num1 = middle->val;
        num2 = l2->val;
        if(flag == 0){
            num1 = num1 + num2;
        }
        else{
            num1 = num1 + num2 + 1;
        }
        if(num1 > 9){
            flag = 1;
            num1 = num1 % 10;
        }
        else flag = 0;
        middle->val = num1;
        
        
        
        if(!middle->next&&!l2->next){
            if(flag == 1){
                ListNode *last = new ListNode;
                last->val = 1;
                middle->next = last;
            }
            return l1;
        }
        
        if(l2->next){
            middle->next = l2->next;
        }
        
        middle = middle->next;
        
        while(middle->next){
            if(flag == 1){
                num1 = middle->val + 1;
                if(num1 > 9){
                    flag = 1;
                    num1 = num1 % 10;
                }
                else flag = 0;
                middle->val = num1;
            }
            else{
                flag = 0;
                break;
            }
            middle = middle->next;
        }
        
        num1 = middle->val;
        if(flag == 1){
            num1 = num1 + 1;
        }
        if(num1 > 9){
            flag = 1;
            num1 = num1 % 10;
        }
        else flag = 0;
        middle->val = num1;
        
        if(flag == 1){
            ListNode *last = new ListNode;
            last->val = 1;
            middle->next = last;
        }
        return l1;
    }
};
