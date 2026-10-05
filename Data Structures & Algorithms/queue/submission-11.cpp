class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(int val):val(val),next(nullptr),prev(nullptr){};
    ListNode(int val,ListNode* next): val(val),next(next),prev(nullptr){};
    ListNode(int val,ListNode* next,ListNode* prev): val(val),next(next),prev(prev){};
};
class Deque {
    ListNode* head;
    ListNode* tail;
public:
    Deque() {
        head = new ListNode(-1);
        tail = head;
    }

    bool isEmpty() {
        if(head->next){
            return false;
        }
        return true;
    }

    void append(int value) {
        ListNode* node = new ListNode(value);
        node->prev = tail;
        tail->next = node;
        tail = node;
    }

    void appendleft(int value) {
        ListNode* node = new ListNode(value);

        node->next = head->next;
        node->prev = head;

        if (head->next != nullptr) {
            head->next->prev = node;
        } else {
            // list was empty
            tail = node;
        }

        head->next = node;
    }


    int pop() {
        if(tail==head){
            return -1;
        }
        ListNode* toDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        int val = toDelete->val;
        delete toDelete;
        return val;
    }

    int popleft() {
    if (head->next == nullptr) {
        return -1;
    }

    ListNode* toDelete = head->next;
    int val = toDelete->val;

    head->next = toDelete->next;

    if (head->next != nullptr) {
        head->next->prev = head;
    } else {
        // list is now empty
        tail = head;
    }

    delete toDelete;
    return val;
}

};
