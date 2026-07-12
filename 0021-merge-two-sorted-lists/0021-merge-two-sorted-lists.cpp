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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        ListNode* res = new ListNode(-1);
        if(list1->val>list2->val) res->next = list2;
        else res->next = list1;
        ListNode* ans = res;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                ans->next = temp1;
                ans = ans->next;
                temp1 = temp1->next;
            }
            else if(temp2->val < temp1->val){
                ans->next = temp2;
                ans = ans->next;
                temp2 = temp2->next;

            }
        }
        if(temp1==NULL){
            ans->next = temp2;
        }
        else{
            ans->next = temp1;
        }
        return res->next;
        
    }
};