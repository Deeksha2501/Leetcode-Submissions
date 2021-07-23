class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n , vector<int>(m));
        
        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                mat[i][j] += mat[i][j-1];
            }
        }
        
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                mat[i][j] += mat[i-1][j];
            }
        }
        
        for(int i=0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                int aa = i+k < n ? i+k : n-1;
                int ab = j+k < m ? j+k : m-1;
                
                int add1 = mat[aa][ab];
                
                int sub1 = 0 , sub2=0 , add2 = 0;
                if(j-k-1 >=0){
                    sub1 = mat[aa][j-k-1];
                }
                if(i-k-1 >= 0){
                    sub2 = mat[i-k-1][ab];
                }
                if(i-k-1 >=0 && j-k-1 >=0){
                    add2 = mat[i-k-1][j-k-1];
                }
                
                res[i][j] = add1 + add2 - sub1 - sub2;
                
            }
        }
        
        return res;
        
    }
};