class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size(), m=mat[0].size();
        int i=0, j=m-1;
        while(i <n && j >=0){
            if(target == mat[i][j])return true;
            if(target > mat[i][j]){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};