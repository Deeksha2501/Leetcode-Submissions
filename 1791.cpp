class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        int f, s;
        f = e[0][0];
        s = e[0][1];
        if(e[1][0] == f || e[1][1] == f)return f;
        else return s;
    }
};