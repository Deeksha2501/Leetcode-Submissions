class Solution {
public:
    int lengthOfLIS(vector<int> nums) {
        vector<int> dp(nums.size() , 1);
        
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int longest = 0;
        for (int c: dp) {
            longest = max(longest, c);
        }
        
        return longest;
    }
    
    bool canBeIncreasing(vector<int>& nums) {
        int x=lengthOfLIS(nums);
        if(nums.size()-x>1)return false;
        return true;
    }
};