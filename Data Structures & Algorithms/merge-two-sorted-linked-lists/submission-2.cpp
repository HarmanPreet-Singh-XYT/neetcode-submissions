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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* nodeList = new ListNode(-1);
        ListNode* tail = nodeList;
        while(list1 && list2){
            if(list1->val > list2->val){
                ListNode* node = new ListNode(list2->val);
                tail->next = node;
                tail = node;
                list2 = list2->next;
            }else{
                ListNode* node2 = new ListNode(list1->val);
                tail->next = node2;
                tail = node2;
                list1 = list1->next;
            }
        }
        while(list1){
            ListNode* node = new ListNode(list1->val);
            tail->next = node;
            tail = node;
            list1 = list1->next;
        }
        while(list2){
            ListNode* node = new ListNode(list2->val);
            tail->next = node;
            tail = node;
            list2 = list2->next;
        }
        if(nodeList == tail && nodeList->next){
            tail = nodeList->next;
        }
        nodeList = nodeList->next;
        return nodeList;
    }
};
