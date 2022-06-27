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
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head, *prev = NULL;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int cnt = 0;
        while(l1 && l2) {
            if(cnt%2 == 0) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next =l2;
                l2 = l2->next;
            }
            cur = cur->next;
            cnt++;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head, *fast = head, *prev = NULL;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        slow = reverse(slow);
        merge(head, slow);
    }
};