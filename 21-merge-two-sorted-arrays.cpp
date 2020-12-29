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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ptr = new ListNode(0);
        ListNode* res = ptr;
        while (l1 || l2){
            if (!l2) {
                ptr->next = l1; break;
            }
            if (!l1) {
                ptr->next = l2; break;
            }
            if (l1->val <= l2->val){
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
            }
            else {
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
            }
        }
        return res->next;
    }
};