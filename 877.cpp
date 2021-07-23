class Solution {
public:
    int alex=0, lee=0;
    vector<int> arr;
    vector<vector<int> > dp;
    
    int dfs(int start , int end , int level){
        if(start > end)return 0;
        if(dp[start][end] != -1)return dp[start][end];
        if(level%2 == 0){
            alex += max(arr[start] + dfs(start+1 , end , level+1) , arr[end] + dfs(start, end-1 , level+1));
            return dp[start][end] = alex;
                        
        }else{
            lee += max(arr[start] + dfs(start+1 , end , level+1) , arr[end] + dfs(start, end-1 , level+1));
            return dp[start][end]= lee;   
                       
        }
    }
    
    bool stoneGame(vector<int>& piles) {
        arr = piles;
        int n = piles.size();
        dp = vector<vector<int> >(n+1 , vector<int>(n+1 , -1));
        // dfs(0 , n-1 , 0);
        // if(alex>lee)
            return true;
        // return false;
    }
};