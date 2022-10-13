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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(head->next != NULL) {
            // if(head->val == 0) {
                head = head->next;
                ListNode* cur = new ListNode(0);
                while(head->val != 0) cur->val += head->val, head = head->next;
                temp->next = cur;
                temp = temp->next;
            // }
        }
        return dummy->next;
    }
};