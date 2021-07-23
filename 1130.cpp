class Solution {
public:
    vector<int> nums;
    vector<vector<int>> mem;
    
    int mcm(int i , int j){
        if(i >= j)return 0;
        int res = INT_MAX;
        int max_start = nums[i];
        
        if(mem[i][j] != -1)return mem[i][j];
        
        for(int k = i ; k < j ; k++){
            if(nums[k] > max_start)max_start = nums[k];
            int left = mcm(i ,k);
            int right = mcm(k+1 , j);
            int max_end = nums[k+1];
            for(int d = k+1 ; d<=j ; d++){
                max_end = max(nums[d] , max_end);
            }
            int ans = left + right + max_end*max_start;
            res = min(res , ans);
        }
        
        return mem[i][j] = res;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        nums = arr;
        int n = arr.size();
        mem = vector<vector<int>>(n+1 , vector<int>(n+1 , -1));
        return mcm(0 , n-1);
    }
};