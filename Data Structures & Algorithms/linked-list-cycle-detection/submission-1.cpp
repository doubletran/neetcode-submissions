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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode* fast = head->next;
        ListNode* curr;
        for (ListNode * curr = head; curr != nullptr && fast != nullptr; curr = curr->next){
            if (curr == fast  || fast->next == curr){
                return true;
            }
            if (fast->next){
                fast = fast->next->next;
            }
            else{
                return false;
            }
        }
        return false;
    }
};
