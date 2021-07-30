class Solution {
public:
    vector<vector<char>> arr;
    string s;
    int n, m, nn;
    
    bool dfs(int i , int j, int k){
        if(k >= nn)return true;
        if(i <0 || i >=n || j < 0 || j >= m)return false;
        if(arr[i][j] == '*')return false;
        if(arr[i][j] != s[k])return false;
        
        char temp = arr[i][j];
        arr[i][j] = '*';

        // cout<<"\ni = "<<i<<" j = "<<j;
        // cout<<"\nk = "<<k;
        
        if(dfs(i+1 , j , k+1))return true;
        if(dfs(i , j+1 , k+1))return true;
        if(dfs(i-1 , j , k+1))return true;
        if(dfs(i , j-1 , k+1))return true;
        arr[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& b, string word) {
        n = b.size();
        m = b[0].size();
        nn = word.size();
        s = word;
        arr = b;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(arr[i][j] == word[0]){
                    if(dfs(i , j , 0 ) == true)return true;
                }
            }
        }
        return false;
    }
};