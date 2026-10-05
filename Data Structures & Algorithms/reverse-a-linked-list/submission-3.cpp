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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return head;
        }
        stack<int> st;
        while(head){
            st.push(head->val);
            head = head->next;
        }

        ListNode* rev = new ListNode(st.top());
        st.pop();
        ListNode* tail = rev;
        while(!st.empty()){
            tail->next = new ListNode(st.top());
            tail = tail->next;
            st.pop();
        }
        return rev;
    }
};
