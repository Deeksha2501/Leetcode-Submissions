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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int move = a-1;
        ListNode* head = list1;
        
        while(list1 && move--){
            list1 = list1->next;
        }
        
        // cout<<"list1 = "<<list1->val;
        
        ListNode* rem = list1->next;
        list1->next = list2;
        
        int k = b-a+1;
        
        while(rem && k--){
            rem = rem->next;
        }
        
        ListNode* d = list2;
        while(d->next){
            d = d->next;
        }
    
        d->next = rem;
        
        return head;
        
    }
};