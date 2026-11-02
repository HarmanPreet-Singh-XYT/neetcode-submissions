class ListNode{
    public:
        int val;
        ListNode* next = nullptr;
        ListNode(int val){
            this->val = val;
        }
};
class MyLinkedList {
    ListNode* head;
    ListNode* tail;
public:
    MyLinkedList() {
        head = new ListNode(-1);
        tail = head;
    }
    
    int get(int index) {
        int i = 0;
        ListNode* curr = head->next;
        while(curr && i != index){
            i++;
            curr = curr->next;
        }
        if(i==index && curr){
            return curr->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
        if(head == tail){
            tail = newNode;
        }
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        tail->next = newNode;
        tail = tail->next;
    }
    
    void addAtIndex(int index, int val) {
        int i = 0;
        ListNode* curr = head;
        while(curr){
            if(i==index){
                ListNode* node = new ListNode(val);
                if(!curr->next){
                    tail = node;
                }
                node->next = curr->next;
                curr->next = node;
            }
            i++;
            curr = curr->next;
        }
    }
    
    void deleteAtIndex(int index) {
        int i = 0;
        ListNode* curr = head;
        while(curr && i!=index){
            i++;
            curr = curr->next;
        }
        if(curr && curr->next && i==index){
            if(curr->next == tail){
                if(curr->next->next != nullptr){
                    tail = curr->next->next;
                }else{
                    tail = curr;
                }
            }
            curr->next = curr->next->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */