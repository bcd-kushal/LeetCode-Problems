/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:
Input: head = [1], n = 1
Output: []
Example 3:
Input: head = [1,2], n = 1
Output: [1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(!head->next)
        return NULL;

    struct ListNode* slow=head;
    struct ListNode* fast=head;

    while(fast->next && n>0){
        fast=fast->next;
        n-=1;
    }

    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }

    slow->next=slow->next->next;

    return head;
}
