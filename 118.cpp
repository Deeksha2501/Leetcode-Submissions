class Solution {
public:
    vector<vector<int>> generate(int nums) {
        vector<vector<int>> res;
        vector<int> v(1 , 1);
        res.push_back(v);
        for(int i=2 ; i<=nums ; i++){
            vector<int> v(i , 1);
            v[0] = 1;
            v[i-1] = 1;
            for(int j = 1 ; j<=i-2 ; j++){
                v[j] = res[i-2][j-1] + res[i-2][j];
            }
            res.push_back(v);
        }
        return res;
    }
};