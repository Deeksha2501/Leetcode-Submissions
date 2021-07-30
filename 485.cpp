class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, res=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 1){
                cnt++;
            }else{
                res = max(res , cnt);
                cnt=0;
            }
        }
        res = max(res , cnt);
        return res;
    }
};