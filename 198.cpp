class Solution {
public:
    vector<int> arr;
    int n;
    vector<vector<int>> mem;
    
    int dfs(int i , bool flag){
        if(i >= n){
            return 0;
        }
        if(mem[i][flag] != -1)return mem[i][flag];
        if(flag){
            return mem[i][flag] = max({
                arr[i] + dfs(i+1 , false),
                dfs(i+1 , true)
            });
        }else{
            return mem[i][flag] = dfs(i+1 , true);
        }
    }
    
    int rob(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        mem = vector<vector<int>>(n , vector<int>(2 , -1));
        return dfs(0 , true);
    }
};

