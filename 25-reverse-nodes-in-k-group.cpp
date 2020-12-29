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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev = nullptr, *cur = head, *next, *end = head;
        ListNode *origin = new ListNode(0);
        ListNode *origin2 = origin;
        origin->next = head;
        for (int i = 0; i < k - 1; i++){
            end = end->next;
        }
        while (end != nullptr){
            origin->next = end;
            origin = cur;
            for (int i = 0; i < k; i++){   
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;  
                end = end? end->next:nullptr;
            }
            origin->next = cur;
        }
        return origin2->next;
    }
};