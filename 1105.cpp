class Solution {
public:
    vector<vector<int>> arr;
    vector<vector<int> >dp;
    int n, sw;
    
    int dfs(int i , int w , int max_h){
        if(i >= n)return max_h;
        if(dp[i][w] != -1)return dp[i][w];
        int temp_res = max_h + dfs(i+1 , arr[i][0] , arr[i][1]);
        if(w + arr[i][0] <= sw){
            return dp[i][w] = min({
                dfs(i+1 , w+arr[i][0] , max(arr[i][1] , max_h)),
                temp_res
            });
        }else{
            return dp[i][w] = temp_res;
        }
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        arr = books;
        sw = shelf_width;
        n = arr.size();
        dp = vector<vector<int>>(n+1 , vector<int>(sw+1 , -1));
        return dfs(0 , 0 , 0);
    }
};