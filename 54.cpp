class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int is =0, js=0;
        vector<int> res;
        
        while(true){
            if(is < n)
            for(int j=js ; j<m ; j++){
                res.push_back(mat[is][j]);
                // cout<<"\n1 "<<mat[is][j];
            }
            is++;
            // js = m-1;
            if(js < m)
            for(int i=is  ; i<n ; i++){
                res.push_back(mat[i][m-1]);                
                // cout<<"\n2 "<<mat[i][m-1];
            }
            m--;
            // js = m-1;
            // is = n-1;
            // cout<<"\njs = "<<js<<" m = "<<m;
            // cout<<"\nis = "<<is<<" n = "<<n;
            if(is < n)
            for(int j=m-1 ; j>=js ; j--){
                res.push_back(mat[n-1][j]);   
                // cout<<"\n3 "<<mat[n-1][j];
            }
            n--;
            if(js<m)
            for(int i=n-1 ; i>=is ; i--){
                res.push_back(mat[i][js]);
                // cout<<"\n4 "<<mat[i][js];
            }
            js++;
            if(is >= n || js>=m)break;
        }
        return res;
    }
};