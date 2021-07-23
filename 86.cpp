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
    
    void print(ListNode* head){
        if(head == NULL)return;
        cout<<head->val<<" ";
        print(head->next);
    }
    
    ListNode* partition(ListNode* head, int x) {
        ListNode* first=NULL, *second=NULL , *f_tail=NULL;
        ListNode *curr = head;
        while(curr != NULL){
            // cout<<curr->val<<"\n";
            if(curr->val < x){
                if(first == NULL )  {
                    head = curr;
                    first = curr;
                }else{
                    first->next = curr;
                    first = first->next;
                }
            }else{
                if(second == NULL){
                    second = curr;
                    f_tail = curr;
                }else{
                    second->next = curr;
                    second = second->next;
                    
                }
            }
            curr = curr->next;
        }
        
        if(second)second->next = NULL;
        
        
        if(first != NULL){
            first->next = f_tail;
            
        }else{
            head = f_tail;
        }
        
        return head;
        
    }
};