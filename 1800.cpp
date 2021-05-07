class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int prev = nums[0];
        int maxm = nums[0];
        for(int i=1 ; i<nums.size(); i++) {
            if(nums[i]>prev)sum += nums[i];
            else{
                maxm = max(sum , maxm);
                sum = nums[i];
            }
            prev = nums[i];
        }
        maxm = max(sum , maxm);
        return maxm;
    }
};

