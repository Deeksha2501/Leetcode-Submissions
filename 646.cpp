class Solution {
public:
    vector<vector<int>> arr;
    int n;
    
    vector<vector<int>> mem;
    
    int dfs(int i , int prev){
        if(i >= n)return 0;
        if(mem[i][prev + 2000] != -1)return mem[i][prev + 2000];
        int x = dfs(i+1 , prev);
        if(arr[i][0] > prev){
            return mem[i][prev + 2000] = max(1 + dfs(i+1 , arr[i][1]), x);
        }
        return mem[i][prev + 2000] = x;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        arr = pairs;
        sort(arr.begin() , arr.end());
        n = arr.size();
        
        mem = vector<vector<int> >(n+1 , vector<int>(4000 , -1));
        
        return dfs(0 , -2000);
    }
};