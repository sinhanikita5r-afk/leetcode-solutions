/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int lengthofLinkedList(ListNode* fast, ListNode* slow) {
    int cnt = 1;
    fast = fast->next;

    while (fast != slow) {
        cnt++;
        fast = fast->next;
    }

    return cnt;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: detect cycle
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                // Step 2: find length of cycle
                int len = lengthofLinkedList(fast, slow);

                // Step 3: two pointers
                ListNode* p1 = head;
                ListNode* p2 = head;

                // p2 ko cycle length jitna aage karo
                for (int i = 0; i < len; i++) {
                    p2 = p2->next;
                }

                // dono same speed se move karenge
                while (p1 != p2) {
                    p1 = p1->next;
                    p2 = p2->next;
                }

                return p1;
            }
        }

        return nullptr;
    }
};