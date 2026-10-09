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
    ListNode* deleteMiddle(ListNode* head) {
        int res=0;
        int n=0;
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode* temp=head;
        
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        res=n/2;
        temp=head;
        while(temp!=nullptr){
            res--;
            if(res==0){
              ListNode* middle=temp->next;
                temp->next=temp->next->next;
                delete(middle);
                break;
            }
            temp=temp->next;

        }
        return head;
        
    }
};