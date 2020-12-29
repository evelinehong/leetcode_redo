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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *res2 = res;
        int carry = 0;
        int sum = 0;
        while (l1 || l2 || carry){
            sum = ((l1?l1->val:0) + (l2?l2->val:0) + carry) % 10 ;
            carry = ((l1?l1->val:0) + (l2?l2->val:0) + carry) / 10;
            res->next = new ListNode(sum);
            res = res->next;
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
        }
        return res2->next;
    }
};