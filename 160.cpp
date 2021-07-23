/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    int getLength(ListNode* head){
        if(head == NULL)return 0;
        return 1+getLength(head->next);
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = getLength(headA);
        int n2 = getLength(headB);
        int k = abs(n1-n2);
        ListNode *first = headA , *second = headB;
        if(n1 > n2){
            while(k--){
                first = first->next;
            }
        }else{
            while(k--){
                second = second->next;
            }
        }
        
        while(first && second && first != second){
            first = first->next;
            second = second->next;
        }
        
        return first;
        
    }
};


