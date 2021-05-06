class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        for(int i=0 ; i<mat.size() ; i++){
            sum += mat[i][i];
            int k = mat.size()-i-1;
            if(k!=i)sum += mat[k][i];
        }
        return sum;
    }
};