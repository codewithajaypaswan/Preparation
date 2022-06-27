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
    vector<int> nextLargerNodes(ListNode* head) {
        int n = 0, i = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            n++;
        }
        vector<int>ans(n, 0);
        stack<pair<int,int>>st;
        temp = head;
        while(temp) {
            while(!st.empty() && st.top().first < temp->val) {
                ans[st.top().second] = temp->val;
                st.pop();
            }
            st.push({temp->val, i});
            i++; temp = temp->next;
        }
        return ans;
    }
};