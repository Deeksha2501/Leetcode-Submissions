class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> res(n);
        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && st.top() <= nums2[i])st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        unordered_map<int,int> map;
        for(int i=0;i<nums2.size();i++)map[nums2[i]] = i;
        for(int i=0;i<nums1.size();i++){
            nums1[i]=res[map[nums1[i]]];
        }
        return nums1;
    }
};