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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(INT_MIN);
        for (auto &l: lists){
            res = mergeTwoLists (res, l);
        }
        return res->next;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* result = res;
        while (l1 || l2){
            if (!l2) {res->next = l1; break;}
            if (!l1) {res->next = l2; break;}
            if (l1->val < l2->val) {
                res->next = l1;    
                l1 = l1->next;
            }
            else {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        return result->next;
    }
};