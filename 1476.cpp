class SubrectangleQueries {
    vector<vector<int>> rec;
    int n, m;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->rec = rectangle;
        
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        // for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<m ; j++){
        //         cout<<rec[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        for(int i=row1 ; i<=row2 ; i++){
            for(int j=col1 ; j<=col2 ; j++){
                rec[i][j] = newValue;
            }
        }
        // cout<<"\n----------------------\n";
        // for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<m ; j++){
        //         cout<<rec[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
    }
    
    int getValue(int row, int col) {
        return rec[row][col];
    }
};