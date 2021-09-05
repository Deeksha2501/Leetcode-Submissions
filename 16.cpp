class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int res = nums[0] + nums[1] + nums[nums.size()-1];

        for(int i=0 ; i<nums.size()-2 ; i++){
            int st = i+1, end = nums.size()-1;
            while(st < end){
                int sum = nums[i] + nums[st] + nums[end];
                if(sum < target){
                    st++;
                }else{
                    end--;
                }
                if(abs(target-sum) < abs(target-res)){
                    res = sum;
                }
            }
        }
        return res;
    }
};