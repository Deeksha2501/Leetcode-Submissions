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
        ListNode* o=NULL;
        ListNode* os = head;
        ListNode* e=NULL;
        ListNode* es=NULL;
        int c = 1;
        while(head){
            ListNode *t = head->next;
            // cout<<"\ncurrently processing = "<<head->val;
            if(c%2){
                // cout<<"\nodd";
                if(o){
                    o->next = head;
                    o = o->next;
                }else{
                    o = head;
                }
            }else{
                // cout<<"\neven";
                if(e){
                    e->next = head;
                    e= e->next;
                }else{
                    e = head;
                    es = head;
                }
            }
            head = t;
            c++;
        }
        if(o)
        o->next = es;
        if(e)e->next = NULL;
        return os;
    }
};