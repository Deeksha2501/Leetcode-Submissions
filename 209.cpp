class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res= INT_MAX;
        int sum=0,i=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                res=min(res,j+1-i);
                sum-=nums[i++];
            }
        }
        return (res!=INT_MAX)?res:0;
    }
};