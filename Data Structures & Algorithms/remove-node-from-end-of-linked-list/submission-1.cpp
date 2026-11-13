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
    int remove(ListNode* curr, int n){
        if (!curr){
            return 0;
        }
        int counter = remove(curr->next, n);
        if (counter == n){
            curr->next = curr->next->next;
        }
        return counter + 1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (remove(head, n) == n){
            head = head->next;
        }
        return head;
    }
};
