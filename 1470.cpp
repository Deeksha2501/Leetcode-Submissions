class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int x=0; 
        int y=n;
        vector<int> res;
        while(x<n and y<nums.size()){
            res.push_back(nums[x]);
            res.push_back(nums[y]);
            x++;y++;
        }
        return res;
    }
};