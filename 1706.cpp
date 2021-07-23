class Solution {
public:
    vector<vector<int>> arr;
    int n, m;
    
    int dfs(int i , int j){
        // cout<<"\ni = "<<i<<" j = "<<j;
        if(i == n)return j;
        if(j < 0 && j >= m){
            return -1;
        }
        if(arr[i][j] == 1){
            if(j<m-1 && arr[i][j+1] != -1)return dfs(i+1 , j+1);
            else return -1;
        }
        else{
            if(j>0 && arr[i][j-1] != 1)return dfs(i+1 , j-1);
            else return -1;
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        arr = grid;
        n =  grid.size();                               ;
        m = grid[0].size();
        vector<int> res(m);
        for(int i=0 ; i<m ; i++){
            res[i] = dfs(0 , i);
        }
        return res;
    }
};
