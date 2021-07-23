class Solution {
public:
    vector <double> prefix;
    vector < vector <double> > dp;
    double recur(vector <int>& nums, int i, int k) {
        if (k <= 0) return 0;
        if (dp[i][k] != -1.00) return dp[i][k];
        if (k == 1) {
            if (i == 0) return dp[i][k] = (double)(prefix[nums.size()-1])/(double)(nums.size());
            return dp[i][k] = (double)(prefix[nums.size()-1] - prefix[i - 1])/(double)(nums.size() - i);
        }
        double  t = 0;
        for (int j = i; j < nums.size(); j++) {
            if (i == 0) t = max(t , (double)(prefix[j])/(double)(j + 1)+ recur(nums, j + 1, k - 1));
            else t = max(t , (double)(prefix[j] - prefix[i - 1])/(double)(j - i + 1)+ recur(nums, j + 1, k - 1));
        }
        return dp[i][k] = t;
    }
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        dp.assign(nums.size() + 1, vector <double> (k + 1 , -1.00));
        prefix.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(nums[i] + prefix[i - 1]);
        }
        return recur(nums, 0, k);
    }
};