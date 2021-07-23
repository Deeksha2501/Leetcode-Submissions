class Solution {
public:
    int get(vector<int> nums){
        int maxEnding = nums[0] , res = nums[0];
        for(int i=1 ; i<nums.size() ; i++){
            maxEnding = max(maxEnding + nums[i] , nums[i]);
            res = max(res, maxEnding);
        }
        
        return res;
    }
    
    int maxAbsoluteSum(vector<int>& nums) {
        int pSum = get(nums);
        for(int i=0 ; i<nums.size() ; i++)nums[i] = -nums[i];
        int nSum = get(nums);
        return max(pSum , nSum);
    }
};