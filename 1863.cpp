class Solution {
public:
    vector<int> arr;
    int n;
    
    int dfs(int i , int xr){
        if(i == n)return xr;
        return dfs(i+1 , xr^arr[i]) + dfs(i+1 , xr);
    }
    
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        return dfs(0 , 0);
    }
};