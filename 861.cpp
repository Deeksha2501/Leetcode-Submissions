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

