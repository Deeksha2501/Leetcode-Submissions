class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(),n;
        if(m != 0)n = mat[0].size();
        else return mat;
        
        if(n == 0)return mat;
        
        if((m * n) != (r*c))return mat;
        vector<int> temp;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                temp.push_back(mat[i][j]);
            }
        }
        
        int curr = 0;
        
        vector<vector<int>> res;
        
        for(int i=0 ; i<r ; i++){
            vector<int> t;
            for(int j=0 ; j<c ; j++){
                t.push_back(temp[curr]);
                curr++;
            }
            res.push_back(t);
        }
        
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(),n;
        if(m != 0)n = mat[0].size();
        else return mat;
        
        if(n == 0)return mat;
        
        if((m * n) != (r*c))return mat;
        
        // vector<vector<int>> res;
        vector<vector<int>> res( r , vector<int> (c));
        
        int rr=0,cc=0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                res[rr][cc] = mat[i][j];
                cc++;
                if(cc == c){
                    rr++;
                    cc=0;
                }
            }
        }

        return res;
    }
};