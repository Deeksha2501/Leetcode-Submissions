struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
public:
    vector<vector<char>> b;
    int n,m;
    
    bool dfs(int i , int j , unordered_set<pair<int , int>, pair_hash > &s){
        if(i < 0 || j < 0 || i >= n || j >= m)return false;
        if(b[i][j] == 'X')return true;
        if(s.find({i , j}) != s.end())return true;
        // cout<<"\ni = "<<i<<" j = "<<j;
        s.insert({i , j});
        bool f = dfs(i+1 , j , s);
        f &= dfs(i , j+1 , s);
        f &= dfs(i-1 , j , s);
        f &= dfs(i , j-1 , s);
        return f;
    }
    
    void solve(vector<vector<char>>& board) {
        b = board;
        n = b.size();
        m = b[0].size();
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(b[i][j] == 'O'){
                    unordered_set<pair<int , int>, pair_hash > s;
                    // cout<<"j";
                    bool ans = dfs(i , j , s);
                    cout<<ans;
                    if(ans){
                        for(auto p : s){
                            b[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }
        board = b;
    }
};