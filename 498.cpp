class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        // res.push_back(mat[0][0]);
        int dir = 1, n = mat.size(), m = mat[0].size();
        bool flag=true;
        int count = n*m;
        // int count = 10;
        int i=0 , j=0;
        while(count){
            if(flag == true){
                while(i>=0 && j<m){
                    res.push_back(mat[i][j]);
                    count--;
                    i--;
                    j++;
                }
                if(i == -1 && j != m){
                    i = 0;
                }else if(j == m){
                    i = i+2;
                    j = m-1;
                }
                flag = false;
            }else{
                while(j>=0 && i<n){
                    res.push_back(mat[i][j]);
                    count--;
                    i++;
                    j--;
                }
                if(j == -1 && i != n){
                    j = 0;
                }else if(i == n){
                    i = n-1;
                    j = j+2;
                }
                flag = true;
            }
        }
        return res;
        
    }
};
