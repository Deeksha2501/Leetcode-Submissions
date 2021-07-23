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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0 ; i<nums.size() ; i++){
            s.insert(nums[i]);
        }
        
        bool flag = false;
        int count=0;
        
        ListNode* curr = head;
        while(curr){
            if(s.find(curr->val) == s.end() && flag == true){
                // cout<<"count incr";
                count++;
                flag = false;
            }
            if(s.find(curr->val) != s.end()){
                // cout<<"found true";
                flag = true;
            }
            curr = curr->next;
        }
        if(flag)count++;
        return count;
        
    }
};