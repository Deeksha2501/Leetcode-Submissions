class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int sum) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int i=0, j=n-1;
        set<vector<int>> res;
        for(int i=0 ; i<n-3 ; i++){
            for(int j=i+1 ; j<n-2 ; j++){
                int st = j+1, end = n-1;
                int target = sum - (nums[i]+nums[j]);
                while(st < end){
                    int s = nums[st] + nums[end];
                    if(s == target){
                        res.insert({nums[i] , nums[j], nums[st] , nums[end]});
                        st++;
                        end--;
                    }else if(s < target){
                        st++;
                    }else end--;
                }
            }
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};


//https://leetcode.com/problems/4sum/discuss/8609/My-solution-generalized-for-kSums-in-JAVA