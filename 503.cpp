class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> res(n);
        
        for(int i=n-1 ; i>=0 ; i--){
            s.push(nums[i]);
        }
        
        for(int i=n-1 ; i>=0 ; i--){
            while(!s.empty() && s.top() <= nums[i]){
                s.pop();
            }
            res[i] = s.empty() ? -1 : s.top();
            s.push(nums[i]);
        }
        return res;
    }
};