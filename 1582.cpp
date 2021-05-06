class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> col(m,0);
        vector<int> row;
        vector<int> cols;
        for(int i=0 ;i<mat.size() ; i++)   {
            int sum=0;
            for(int j=0 ; j<mat[i].size() ; j++){
                sum += mat[i][j];
                col[j] += mat[i][j];
            }
            // cout<<"\nsum = "<<sum;
            if(sum == 1)row.push_back(i);
        }
        

        
        for(int i=0 ; i<m ; i++){
            // cout<<"\ncol[i]"<<col[i];
            if(col[i] == 1)cols.push_back(i);
        }
        
        int count=0;
        
        for(int a: row){
            // cout<<"\na = "<<a;
            for(int b: cols){
                // cout<<"\nb = "<<b;
                
                if(mat[a][b]==1){
                    
                    count++;
                    continue;
                }
            }
        }
        return count;
    }
};