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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1 = new ListNode(0);
        ListNode* p2 = new ListNode(0);
        ListNode *head1 = p1, *head2 = p2;
        while(head != NULL) {
            if(head->val < x) {
                head1->next = head;
                head1 = head1->next;
            }
            else {
                head2->next = head;
                head2 = head2->next;
            }
            head = head->next;
        }
        head2->next = NULL;
        head1->next = p2->next;
        return p1->next;
    }
};