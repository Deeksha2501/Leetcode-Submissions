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
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode*prev = new ListNode(-200);
        prev->next = head;
        ListNode* ans = prev;
        ListNode* curr = head;
        
        unordered_set<int> s;
        
        while(curr){
            int temp = -200;
            while(curr && s.find(curr->val) != s.end()){
                temp = curr->val;
                curr = curr->next;
            }
            if(temp != 200)s.erase(temp);
            if(!curr)break;
            s.insert(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        while(curr != NULL){
            if(s.find(curr->val) == s.end()){
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete(temp);
            }else{
                prev = curr;
                curr= curr->next;
            }
        }
        // print(ans);
        return ans->next;
    }
};




#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode *head){
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
}

ListNode *takeinput(){
	int data;
	cin>>data;
	ListNode *head = NULL;
	ListNode *prev , *created;
	while(data != -200){
		created = new ListNode(data);
		if(head == NULL){
			head = created;
			prev = created;
		}
		else{
			prev->next = created;
			prev = created;
		}
		cin>>data;
	}
	return head;
}

ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
		return head;
	    }
        ListNode *curr = head->next;
        ListNode *prev = head;
        int flag = 0;
        while(curr != NULL){
            if(prev->val == curr->val){
                prev->next = curr->next;
                delete(curr);
                curr = prev->next;
                flag = 1;
            }else{
                if(flag == 1)
                    prev->val = -200;
                flag = 0;
                curr = curr->next;
                prev = prev->next;
            }
        }
        if(flag)prev->val = -200;
        print(head);
        cout<<"---";
        curr = head ; prev = NULL;
        int count = 0;
        while(curr != NULL  && count<20){
            if(curr->val == -200){
                if(curr == head){
                    head = curr->next;
                    // cout<<"head changed";
                    delete(curr);
                    curr = head;
                    prev = NULL;
                }else{
                    // cout<<"\nyha hui gadbad";
                    prev->next = curr->next;
                    // cout<<"\nprev->data = "<<prev->val;
                    // cout<<"\ncurr->data = "<<curr->val;
                    delete(curr);
                    curr = prev->next;
                    // cout<<"\nnew curr->data = "<<curr->val;
                }
            }else{
                // cout<<"\ncurr = "<<curr->val;
                curr = curr->next;
                if(prev == NULL)
                prev = head;
                else
                {
                    prev = prev->next;
                }
                
            }
            count++;
        }
        // cout<<"head = "<<head->val;
        return head;
    }

int main(){
    ListNode *head = takeinput();
    head = deleteDuplicates(head);
    print(head);
    return 0;
}