/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->child != nullptr) {
                Node* child = temp->child;
                Node* next = temp->next;

                // temp ko child se jodo
                temp->next = child;
                child->prev = temp;
                temp->child = nullptr;   // important!

                // child list ki tail dhundo
                Node* tail = child;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }

                // tail ko original next se jodo
                tail->next = next;
                if (next != nullptr) {
                    next->prev = tail;
                }
            }
            temp = temp->next;
        }

        return head;
    }
};