class NumMatrix {
    
    vector<vector<int>> m;
    vector<vector<int>> temp;
    int rows;
    int cols;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix;
        int rows = m.size();
        int cols = m[0].size();
        temp = vector<vector<int>>(rows, vector<int>(cols, 0));
        for(int i=0 ; i<rows ; i++){
            temp[i][0] = m[i][0];
            for(int j=1 ; j< cols ; j++){
                temp[i][j] += temp[i][j-1] + m[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1 ; i<=row2 ; i++){
            if(col1 != 0)sum += temp[i][col2]-temp[i][col1-1];
            else sum += temp[i][col2];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */