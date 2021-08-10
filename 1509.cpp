class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n < 4)return 0;
        int temp1 = nums[n-4]-nums[0];
        int temp2 = nums[n-3]-nums[1];
        int temp3 = nums[n-2]-nums[2];
        int temp4 = nums[n-1]-nums[3];
        return min({temp1 , temp2, temp3, temp4});
    }
};


class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        if(nums.size()<=3){
            return 0;
        }
        else{
            int i = nums.size()-1-3;
            int j = 3;
            int temp1 = nums[nums.size()-3] - nums[1];
            int temp2 = nums[nums.size()-2] - nums[2];
            int res = min(temp1, temp2);
            res = min(res, nums[i]-nums[0]);
            return min(res, nums[nums.size()-1]-nums[j]);
        }
    }
};