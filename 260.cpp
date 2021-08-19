class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xr = 0 , n = nums.size();
        
        for(int i=0 ; i<n ; i++){
            xr ^= nums[i];
        }
        
        long bit = (xr&(~(xr-1)));
        
        int num1 = 0, num2 = 0;
        for(int i=0 ; i<n ; i++){
            if((nums[i] & bit) > 0){
                num1 ^= nums[i];
            }else{
                num2 ^= nums[i];
            }
        }
        return {num1 , num2};
    }
};
