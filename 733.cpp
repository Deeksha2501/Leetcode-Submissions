class Solution {
public:
    vector<vector<int>> mat;
    int nc;
    int x,y;
    int color;
    
    bool isValid(int i , int j){
        return (i >=0 && i < mat.size() && j >=0 && j < mat[0].size() && mat[i][j] == color);
    }
    
    void fill(int i , int j ){
        if(isValid(i , j)){
            mat[i][j] = nc;
            fill(i+1 , j);
            fill(i , j+1);
            fill(i-1 , j);
            fill(i , j-1);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        mat = image;
        nc = newColor;
        x=sr;y=sc;
        color = mat[sr][sc];
        if(color == newColor)return mat;
        fill(x , y);                               
        return mat;
    }
};