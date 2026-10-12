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
ListNode* getKthNode(ListNode* temp, int k){
    k-=1;
    while(temp!=nullptr && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while (temp != nullptr) {
            ListNode* kthNode = getKthNode(temp, k);

            // k se kam nodes bache hain, reverse nahi karna
            if (kthNode == nullptr) {
                if (prevNode) prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next; // agle group ka start save karo
            kthNode->next = nullptr;            // current group ko alag karo

            reverseList(temp);                  // temp ab group ka tail ban jayega

            if (temp == head) {
                head = kthNode;                 // pehle group ka naya head
            } else {
                prevNode->next = kthNode;       // pichhle group ko jodo
            }

            prevNode = temp;                    // temp ab is group ka last node hai
            temp = nextNode;
        }
        return head;
    }
};