class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        int sum=0;
        for(i=0 ; i<nums.size() ; i+=2){
            sum += min(nums[i], nums[i+1]);
        }
        return sum;
    }
};