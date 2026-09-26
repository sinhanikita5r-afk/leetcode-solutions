class MyLinkedList {
public:

    ListNode* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        ListNode* temp = head;
        int count = 0;

        while(temp != nullptr) {
            if(count == index) {
                return temp->val;
            }

            count++;
            temp = temp->next;
        }

        return -1;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);

        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {

        if(head == nullptr) {
            head = new ListNode(val);
            return;
        }

        ListNode* temp = head;

        while(temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = new ListNode(val);
    }

    void addAtIndex(int index, int val) {

        if(index == 0) {
            addAtHead(val);
            return;
        }

        if(head == nullptr) {
            return;
        }

        ListNode* temp = head;
        int count = 0;

        while(temp != nullptr && count < index - 1) {
            temp = temp->next;
            count++;
        }

        if(temp == nullptr) {
            return;
        }

        ListNode* newNode = new ListNode(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {

        if(head == nullptr) {
            return;
        }

        if(index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* temp = head;
        int count = 0;

        while(temp != nullptr && count < index - 1) {
            temp = temp->next;
            count++;
        }

        if(temp == nullptr || temp->next == nullptr) {
            return;
        }

        ListNode* deleteNode = temp->next;
        temp->next = temp->next->next;

        delete deleteNode;
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