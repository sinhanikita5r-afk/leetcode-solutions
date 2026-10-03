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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1: Count total nodes
        int cnt = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        // Step 2: If head itself has to be deleted
        if (cnt == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 3: Find the node just before the node to delete
        int res = cnt - n;

        temp = head;

        while (res > 1) {
            temp = temp->next;
            res--;
        }

        // Step 4: Delete temp->next
        ListNode* node = temp->next;
        temp->next = temp->next->next;
        delete node;

        return head;
    }
};