class Solution {
public:
    vector<vector<int>>dirs{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    vector<vector<bool>> vis;
    vector<vector<int>> arr;
    int n,m;
    
//     int dfs(int i , int j){
//         cout<<"\ni = "<<i<<" j = "<<j;
//         if(i == n-1 && j == m-1)return 1;
//         if(i <0 || i >=n || j<0 || j >=m)return INT_MAX;
//         if(arr[i][j] == 1)return INT_MAX;
//         if(dp[i][j] != -1)return dp[i][j];
        
//         int mn = INT_MAX;
//         for(int k=0 ; k<8 ; k++){
//             int temp = dfs(i + dirs[k][0] , j+dirs[k][1]);
//             if(temp != INT_MAX){
//                 mn = min(mn , 1+temp);
//             }
//         }
//         return dp[i][j] = mn;
//     }
    
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        arr = grid;
        vis = vector<vector<bool>>(n+1 , vector<bool>(m , false));

        queue<pair<int , int>> q;
        if(arr[0][0] != 0)return -1;
        q.push(make_pair(0 , 0));
        int cnt = 0;
        while(q.size() > 0){
            int nn = q.size();
            for(int i=0 ; i<nn ; i++){
                pair<int , int> p = q.front();
                q.pop();
                if(p.first == n-1 && p.second == m-1 )return cnt+1;
                for(auto d : dirs){
                    int x = p.first+d[0];
                    int y = p.second+d[1];
                    if(x<0 || y<0 || x >= n || y>=m || vis[x][y] == true || arr[x][y] == 1)continue;
                    vis[x][y] = true;
                    q.push(make_pair(x , y));
                }
            }
            cnt++;
        }
        return -1;
    }
};