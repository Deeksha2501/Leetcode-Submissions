class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> arr = nums;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            nums[i] = arr[arr[i]];
        }
        return nums;
    }
};