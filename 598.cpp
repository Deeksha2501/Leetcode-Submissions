class Solution {
public:
    int maxCount(int n, int m, vector<vector<int>>& ops) {
        int rmin=n, cmin=m;
        for(auto i : ops){
            rmin = min(rmin , i[0]);
            cmin = min(cmin , i[1]);
        }
        return rmin*cmin;
    }
};