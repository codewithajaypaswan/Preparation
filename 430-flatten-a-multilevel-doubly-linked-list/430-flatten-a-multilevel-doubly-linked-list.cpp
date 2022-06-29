/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* cur = head;
        while(cur) {
            // case - 1 when no child
            if(cur->child == NULL) {
                cur = cur->next;
                continue;
            }
            // case - 2 when we have a child
            Node* temp = cur->child;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = cur->next;
            if(cur->next) {
                cur->next->prev = temp;
            }
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = NULL;
        }
        return head;
    }
};