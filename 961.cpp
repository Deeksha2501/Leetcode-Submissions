class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0 ; i<nums.size()-1 ; i++){
            if(nums[i+1] == nums[i])return nums[i];
        }
        return nums[0];
    }
};