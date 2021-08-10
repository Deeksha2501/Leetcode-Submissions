class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int res = 0, n = nums.size(), l = 0, r = n - 1, mod = (int)1e9 + 7;
        vector<int> pows(n);
        pows[0] = 1;
        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                res = (res + pows[r - l++]) % mod;
            }
        }
        return res;
    }
};