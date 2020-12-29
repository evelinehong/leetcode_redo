/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        for (Node *l1 = head; l1 != nullptr; l1 = l1->next->next){
            Node *l2 = new Node (l1->val);
            l2->next = l1->next;
            l1->next = l2;
        }
        for (Node *l1 = head; l1 != nullptr; l1 = l1->next->next){
            Node *l2 = l1->next;
            if (l1->random) l2->random = l1->random->next;
            else l2->random = nullptr;
        }
        
        Node *newHead = head->next;
        
        for (Node *l1 = head; l1 != nullptr; l1 = l1->next){
            Node *l2 = l1->next;
            l1->next = l2->next;
            if (l1->next) l2->next = l1->next->next;
        }
        
        return newHead;
    }
};