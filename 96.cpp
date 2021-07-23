class Solution {
public:
    vector<int> mem;
    
    int dfs(int n){
        if(n <= 1)return 1;
        if(mem[n] != -1)return mem[n];
        int res=0;
        for(int i=0 ; i<n ; i++){
            int left = dfs(i);
            int right = dfs(n-i-1);
            res += left*right;
        }
        return mem[n] = res;
    }
    
    int numTrees(int n) {
        mem = vector<int>(n+1 , -1);
        return dfs(n);
    }
};