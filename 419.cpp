class Solution {
public:
    vector<vector<char>> b;
    
    void dfs(int i , int j){
        if(!(i >= 0 && i < b.size() && j>=0 && j <b[0].size()))return;
        if(b[i][j] == '.' || b[i][j] == '-')return;
        
        b[i][j] = '-';
        if(i+1 < b.size() && b[i+1][j] == 'X')return dfs(i+1 , j);
        if(j+1 < b[0].size() && b[i][j+1] == 'X')return dfs(i , j+1);
    }
    
    int countBattleships(vector<vector<char>>& board) {
        b = board;
        int cnt=0;
        for(int i=0 ; i<b.size() ; i++){
            for(int j=0 ; j<b[0].size() ; j++){
                if(b[i][j] == 'X'){
                    dfs(i , j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};