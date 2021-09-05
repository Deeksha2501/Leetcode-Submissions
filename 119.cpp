class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> res;
        vector<int> v(1 , 1);
        res.push_back(v);
        for(int i=2 ; i<=n+1 ; i++){
            vector<int> v(i , 1);
            for(int j = 1 ; j<=i-2 ; j++){
                v[j] = res[i-2][j-1] + res[i-2][j];
            }
            res.push_back(v);
        }
        return res[n];
    }
};