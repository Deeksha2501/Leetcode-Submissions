class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0 ; i<n ; i++){
            if(grid[i][0] == 0){
                for(int j=0 ; j<m ; j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        
        for(int j=0 ; j<m ; j++){
            int cnt=0;
            for(int i=0 ; i<n ; i++){
                if(grid[i][j])cnt++;
            }
            // cout<<"\ncnt = "<<cnt;
            int limit = n/2;
            if(n%2)limit++;
            if(cnt < limit){
                for(int i=0 ; i<n ; i++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        int sum=0;
        for(int i=0 ; i<n ; i++){
            int num = 0;
            for(int j=m-1 ; j>=0 ; j--){
                num += pow(2 , (m-1-j))*grid[i][j];
            }
            sum += num;
        }
        return sum;
    }
};


class Solution {
public:
    int matrixScore(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        for(int i=0 ; i<n ; i++){
            if(g[i][0] == 0){
                for(int j=0 ; j<m ; j++){
                    if(g[i][j] == 0)g[i][j] = 1;
                    else g[i][j] = 0;
                }
            }
        }
        for(int i=0 ; i<m ; i++){
            // cout<<"\n col = "<<i+1;
            int cz = 0, co = 0;
            
            for(int j=0 ; j<n ; j++){
                if(g[j][i] == 1)co++;
                else cz++;
            }
            
            if(cz>co){
                for(int j=0 ; j<n ; j++){
                    if(g[j][i] == 0)g[j][i] = 1;
                    else g[j][i] = 0;
                }
            }
        }
        
        // for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<m ; j++){
        //         cout<<g[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int res=0;
        for(int i=0 ; i<n ; i++){
            int p = 0;
            for(int j = m-1 ; j>=0 ; j--){
                res += g[i][j]*pow(2 , p);
                p++;
            }
        }
        return res;
    }
};

