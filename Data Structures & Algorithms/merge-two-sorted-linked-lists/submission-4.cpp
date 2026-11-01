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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* nodeList = new ListNode(-1);
        ListNode* tail = nodeList;
        while(list1 && list2){
            if(list1->val > list2->val){
                insertTail(list2->val,tail);
                list2 = list2->next;
            }else{
                insertTail(list1->val,tail);
                list1 = list1->next;
            }
        }
        while(list1){
            insertTail(list1->val,tail);
            list1 = list1->next;
        }
        while(list2){
            insertTail(list2->val,tail);
            list2 = list2->next;
        }
        if(nodeList == tail && nodeList->next){
            tail = nodeList->next;
        }
        nodeList = nodeList->next;
        return nodeList;
    }
};
