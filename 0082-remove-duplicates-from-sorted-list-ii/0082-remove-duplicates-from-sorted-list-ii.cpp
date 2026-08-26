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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* temp = new ListNode(0);
        ListNode* curr = head;
        ListNode* prev = temp;
        while(curr!=NULL && prev!=NULL){
           
            while(curr!=NULL && curr->next!=NULL && curr->val==curr->next->val){
                int duplicate = curr->val;
                while(curr!=NULL && curr->val==duplicate){
                    curr = curr->next;
                }
                
            }
            prev->next = curr;
            prev = prev->next;
            if(curr) curr = curr->next;
        }
        return temp->next;
        
    }
};