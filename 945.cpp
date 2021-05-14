class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int k=0;
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i]<=prev){
                k += prev-nums[i]+1;
                nums[i] += prev-nums[i]+1;;
                // cout<<"\nnums[i] set to = "<<nums[i]<<" at i = "<<i;
            }
            prev = nums[i];
        }
        return k;
    }
};