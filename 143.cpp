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
    
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)return;
        vector<int> v;
        ListNode* curr= head;
        while(curr){
            v.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        int i=0, j=v.size()-1;
        int flag=1;
        while(curr){
            if(flag){
                curr->val = v[i];
                i++;
            }else{
                curr->val = v[j];
                j--;
            }
            curr = curr->next;
            flag = !flag;
        }
        
    }
};