class Solution {
public:
    vector<int> arr, mem;
    int n;
    
    int dfs(int target){
        if(target == 0){
            return 1;
        }
        if(mem[target] != -1)return mem[target];
        int sum=0;
        for(int i=0 ; i<n ; i++){
            if(target >= arr[i])sum += dfs(target-arr[i]);
        }
        return mem[target] = sum;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        arr = nums;
        n = arr.size();
        mem = vector<int>(target+1 , -1);
        return dfs(target);
    }
};