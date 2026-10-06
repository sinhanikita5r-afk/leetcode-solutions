/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int>mpp;
        ListNode* tempA=headA;
        while(tempA!=nullptr){
            mpp[tempA]=1;
            tempA=tempA->next;
        }
        ListNode* tempB=headB;
        while(tempB!=nullptr){
            if(mpp.find(tempB)!=mpp.end()){
                return tempB;
            }
            tempB=tempB->next;
        }
        return nullptr;
        
    }
};