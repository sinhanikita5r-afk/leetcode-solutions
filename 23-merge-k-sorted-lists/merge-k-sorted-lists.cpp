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
    ListNode* arrayToLinkedList(vector<int>& arr) {
        if (arr.empty()) return nullptr;

        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;

        for (int i = 1; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];

            while (temp != nullptr) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }

        sort(arr.begin(), arr.end());

        ListNode* head = arrayToLinkedList(arr);

        return head;
    }
};
