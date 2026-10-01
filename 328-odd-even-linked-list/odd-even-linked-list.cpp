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
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr) {
            return head;
        }

        vector<int> arr;

        // Odd position nodes
        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp->val);

            if (temp->next != nullptr) {
                temp = temp->next->next;
            } else {
                break;
            }
        }

        // Even position nodes
        temp = head->next;

        while (temp != nullptr) {
            arr.push_back(temp->val);

            if (temp->next != nullptr) {
                temp = temp->next->next;
            } else {
                break;
            }
        }

        // Put vector values back into linked list
        int i = 0;
        temp = head;

        while (temp != nullptr) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};