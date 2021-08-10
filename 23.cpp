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
    
    
    static bool cmp(ListNode *a, ListNode *b){
        return a->val > b->val;
    }
    
    ListNode* get(vector<ListNode*>& list){
        int n = list.size();
        
        auto comp = [&](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);
        
        for(int i=0 ; i<n ; i++){
            if(list[i] != NULL)pq.push(list[i]);
        }
        
        ListNode* res = new ListNode(0);
        ListNode *head = res;
        
        while(pq.size()>0){
            ListNode* temp = pq.top();pq.pop();
            res->next = temp;
            res = res->next;
            temp = temp->next;
            if(temp)pq.push(temp);
        }
        return head->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return get(lists);
    }
};