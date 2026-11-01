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
    void insertTail(int val, ListNode*& tail){
        ListNode* node = new ListNode(val);
        tail->next = node;
        tail = node;
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* nodeList = new ListNode(-1);
        ListNode* tail = nodeList;
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        for(int x = arr.size()-1;x>=0;x--){
            insertTail(arr[x],tail);
        }
        nodeList = nodeList->next;
        return nodeList;
    }
};
