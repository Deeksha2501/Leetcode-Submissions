class Solution {
public:
    vector<vector<int>> mat;
    
    void transpose(){
        int n = mat.size();
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                swap(mat[i][j] , mat[j][i]);
            }
        }
    }
    
    void reverse(){
        int n = mat.size();
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n/2 ; j++){
                swap(mat[i][j] , mat[i][n-j-1]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        mat = matrix;
        transpose();
        reverse();
        matrix = mat;
        // return mat;
    }
};
