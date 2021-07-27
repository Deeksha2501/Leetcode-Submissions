class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1 , cnt=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 0)cnt++;
            else mul *= nums[i];
            
        }
        
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 0){
                if(cnt == 1){
                    nums[i] = mul;
                }
                else nums[i] = 0;
            }
            else{
                if(cnt == 0)nums[i] = mul/nums[i];
                else nums[i] = 0;
            }
        }
        return nums;
    }
};