class Solution {
public:
    
    static bool cmp(vector<int> a , vector<int> b){
        int x = a[0]*a[0] + a[1]*a[1];
        int y = b[0]*b[0] + b[1]*b[1];
        return x < y;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        
        sort(p.begin() , p.end() , cmp);
        vector<vector<int>> res;
        return vector<vector<int>>(p.begin(), p.begin() + k);
        
    }
};