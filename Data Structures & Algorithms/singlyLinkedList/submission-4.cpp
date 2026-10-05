class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int value){
        this->val = value;
        this->next = nullptr;
    };
    ListNode(int value,ListNode* nextElem){
        this->val = value;
        this->next = nextElem;
    };
};
class LinkedList {
    ListNode* head;
    ListNode* tail;
public:
    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        int i = 0;
        ListNode* temp = head->next;
        while(i <= index && temp!=nullptr){
            if(index == i){
                return temp->val;
            }
            i++;
            temp = temp->next;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head->next;
        head->next = node;
        if(node->next == nullptr){
            tail = node;
        }
    }
    
    void insertTail(int val) {
        ListNode* node = new ListNode(val);
        tail->next = node;
        tail = node;
    }

    bool remove(int index) {
        int i = 0;
        ListNode* temp = head;
        while(temp != nullptr && i < index){
            i++;
            temp = temp->next;
        }
        if(temp != nullptr && temp->next != nullptr){
            if(temp->next == tail){
                tail = temp;
            }
            ListNode* toDelete = temp->next;
            temp->next = temp->next->next;
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
