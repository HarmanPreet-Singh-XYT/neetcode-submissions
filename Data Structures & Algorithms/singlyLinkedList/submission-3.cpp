class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(nullptr){}
    ListNode(int val,ListNode* next):val(val),next(next){}
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
        ListNode* tmp = head->next;
        int i = 0;

        while(tmp != nullptr){
            if(i == index){
                return tmp->val;
            }
            i++;
            tmp = tmp->next;
        }

        return -1;
    }

    void insertHead(int val) {
        ListNode* node;
        node = new ListNode(val);
        node->next = head->next;
        head->next = node;
        if(node->next == nullptr){
            tail = node;
        }
    }
    
    void insertTail(int val) {
        ListNode* node;
        node = new ListNode(val);
        tail->next = node;
        tail = tail->next;
    }

    bool remove(int index) {
        int i = 0;
        ListNode* curr = head;
        while(i<index && curr != nullptr){
            i++;
            curr = curr->next;
        }

        if(curr != nullptr && curr->next != nullptr){
            if(curr->next == tail){
                tail = curr;
            }

            ListNode* deleteNode = curr->next;
            curr->next = curr->next->next;
            delete deleteNode;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> values;
        ListNode* tmp = head->next;
        while(tmp != nullptr){
            values.push_back(tmp->val);
            tmp = tmp->next;
        }
        return values;
    }
};
