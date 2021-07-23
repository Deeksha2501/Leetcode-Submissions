class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0 ; i<n/2 ; i++){
            int sum = nums[i] + nums[n-i-1];
            res = max(res , sum);
        }
        return res;
    }
};