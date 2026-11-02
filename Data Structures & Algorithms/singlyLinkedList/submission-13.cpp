class ListNode{
    public:
        int val;
        ListNode* next = nullptr;
        ListNode(int val){
            this->val = val;
        }
};
class LinkedList {
public:
    ListNode* head;
    ListNode* tail;
    LinkedList() {
       head = new ListNode(-1);
       tail = head;
    }

    int get(int index) {
        int i = 0;
        ListNode* curr = head->next;
        while(curr){
            if(i==index){
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
        if(newNode->next == nullptr){
            tail = newNode;
        }
    }
    
    void insertTail(int val) {
        ListNode* newNode = new ListNode(val);
        tail->next = newNode;
        tail = tail->next;
    }

    bool remove(int index) {
        int i = 0;
        ListNode* curr = head;
        while(i<index && curr->next){
            i++;
            curr = curr->next;
        }
        if(curr && curr->next){
            if(curr->next == tail){
                tail = curr;
            }
            ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }

        return false;
    }

    vector<int> getValues() {
        vector<int> values;
        ListNode* temp = head->next;
        while(temp != nullptr){
            values.push_back(temp->val);
            temp = temp->next;
        }
        return values;
    }
};
