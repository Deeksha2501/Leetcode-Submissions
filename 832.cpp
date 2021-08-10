class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image[0].size(), n = image.size();
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m/2 ; j++){
                swap(image[i][j] , image[i][m-j-1]);
                image[i][j] ^= 1;
                image[i][m-j-1] ^= 1;
            }
            if(m%2 != 0)image[i][m/2] ^= 1;
        }
        return image;
    }
};