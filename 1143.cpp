class Solution {
public:
    vector<vector<int>> mem;
    
    int solve(string s , string t , int i , int j){
        if(i >= s.length() || j >= t.length())return 0;
        if(mem[i][j] != -1)return mem[i][j];
        if(s[i] == t[j]){
            mem[i][j] = 1 + solve(s , t , i+1 , j+1);
        }else{
            mem[i][j] = max(solve(s , t , i+1 , j) , solve(s , t , i , j+1));
        }
        return mem[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();        
        int m = text2.length();
        mem = vector<vector<int>>(n+1 , vector<int>(m+1));
        
        for(int i=0 ; i<m ; i++){
            mem[n][i] = 0;
        }
        
        for(int i=0 ; i<n ; i++){
            mem[i][m] = 0;
        }
        
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=m-1 ; j>=0 ; j--){
                if(text1[i] == text2[j])mem[i][j] = 1 + mem[i+1][j+1];
                else mem[i][j] = max(mem[i][j+1] , mem[i+1][j]);
            }
        }
        
        return mem[0][0];
        
        // return solve(text1 , text2 , 0 , 0);
    }
};