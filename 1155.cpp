class Solution {
public:
    int MOD = 1000000007;
    int f;
    vector<vector<int>> mem;
    
    int dfs(int d , int target){
        if(d == 0 && target == 0)return 1;
        if(d <= 0 || target <= 0)return 0;
        
        if(mem[d][target] != -1)return mem[d][target];
        
        int sum=0;
        for(int i=1 ; i<=f ; i++){
            sum += dfs(d-1 , target-i);
            sum = sum%MOD;
        }
        return mem[d][target] = sum;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        this->f = f;
        mem = vector<vector<int>>(d+1 , vector<int>(target+1 , -1));
        return dfs(d , target);
    }
};