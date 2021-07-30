class Solution {
public:
    int n;
    int cnt=0;
    bool check(int i , int j , vector<string> v){
        for(int ii=i-1, jj=j-1 ; ii>=0&&jj>=0 ; ii--, jj--){
            if(v[ii][jj] == 'Q')return false;
        }
        for(int ii=i-1, jj=j+1 ; ii>=0&&jj<n ; ii--, jj++){
            if(v[ii][jj] == 'Q')return false;
        }
        for(int ii=i-1 ; ii>=0 ; ii--){
            if(v[ii][j] == 'Q')return false;
        }
        return true;
        
    }
    
    void dfs(int i , vector<string> v){
        if(i >= n){
            cnt++;
        }
        for(int j=0 ; j<n ; j++){
            if(check(i , j , v)){
                v[i][j] = 'Q';
                dfs(i+1 , v);
                v[i][j] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        this->n = n;
        string s="";
        vector<string> v;
        for(int i=0 ; i<n ; i++){
            s += ".";
        }
        for(int i=0 ; i<n ; i++){
            v.push_back(s);
        }
        dfs(0 , v);
        return cnt;
    }
};

