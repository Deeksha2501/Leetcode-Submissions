class Solution {
public:
    vector<vector<int>> tri, mem;
        
    int dfs(int i , int j){
        if(i >= tri.size())return 0;
        if(mem[i][j] != -1)return mem[i][j];
        auto v = tri[i];
        int n = v.size();
        if(j+1 >= n)return mem[i][j] = v[j] + dfs(i+1 , j);
        return mem[i][j] = min(v[j] + dfs(i+1 , j) , v[j+1] + dfs(i+1 , j+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        tri = triangle;
        int n = tri.size();
        mem = vector<vector<int>>(n , vector<int>(n+1, -1));
        return dfs(0 , 0);
    }
};
