class Solution {
public:
    vector<vector<int>> g;
    int n , m;
    
    bool check(int i , int j){
        if(i>=0 && j>=0 && i<n && j<m && g[i][j] == 1 )return true;
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        n= grid.size();
        m = grid[0].size();
        g = grid;
        queue<pair<int , int>> q;
        int fresh=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 2)q.push(make_pair(i , j));
                if(grid[i][j] == 1)fresh++;
            }
        }
        int cnt=0;
        if(q.size() == 0 && fresh==0)return 0;
        if(q.size() == 0)return -1;
        while(q.size() > 0){
            int n = q.size();
            
            for(int k=0 ; k<n ; k++){
                pair<int , int> p = q.front();
                int i=p.first;
                int j=p.second;
                q.pop();
                if(check(i+1 , j)){
                    g[i+1][j] = 2;
                    q.push(make_pair(i+1 , j));
                    fresh--;
                }
                if(check(i , j+1)){
                    g[i][j+1] = 2;
                    q.push(make_pair(i , j+1));
                    fresh--;
                }
                if(check(i-1 , j)){
                    g[i-1][j] = 2;
                    q.push(make_pair(i-1 , j));
                    fresh--;
                }
                if(check(i , j-1)){
                    g[i][j-1] = 2;
                    q.push(make_pair(i , j-1));
                    fresh--;
                }
            }
            cnt++;
        }
        return fresh == 0 ? cnt-1 : -1;
    }
};