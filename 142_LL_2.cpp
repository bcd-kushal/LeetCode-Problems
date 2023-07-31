/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer
is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *hare=head, *tortoise=head;
        //int loop_count=0;

        while(hare&&hare->next){
            hare = hare->next->next;
            tortoise = tortoise->next;

            if(hare==tortoise){
                //loop_count+=1;
                tortoise=head;

                while(tortoise!=hare){
                    tortoise = tortoise->next;
                    hare = hare->next;
                }

                return hare;
            }
        }

        return NULL;
    }
};
